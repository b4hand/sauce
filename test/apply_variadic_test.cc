#include <string>
#include <iostream>
#include <sstream>

#include <gtest/gtest.h>

#include <sauce/memory.h>
#include <sauce/internal/apply_variadic.h>

namespace sauce {
namespace test {

using namespace sauce::internal;

template<typename Type>
class Annotation {};

std::string toString(std::string s, int i) {
  std::stringstream buffer;
  buffer << "'" << s << "' '" << i << "'";
  return buffer.str();
}

typedef std::string (*ToString)(std::string, int);

struct DefaultValueParameters {
  template<typename T, int i>
  struct Parameter {
    typedef T Type;

    template<typename Passed>
    T yield(Passed) {
      return T();
    }
  };
};

struct SpecializedParameters {
  template<typename T, int i>
  struct Parameter {};

  template<int i>
  struct Parameter<std::string, i> {
    typedef std::string Type;

    template<typename Passed>
    std::string yield(Passed) {
      return "foobar";
    }
  };

  template<int i>
  struct Parameter<int, i> {
    typedef int Type;

    template<typename Passed>
    int yield(Passed) {
      return 17;
    }
  };
};

struct AnnotatedParameters {
  template<typename T, int i>
  struct Parameter {
    typedef T Type;

    template<typename Passed>
    T yield(Passed) {
      return T();
    }
  };

  template<typename T, int i>
  struct Parameter<Annotation<T>, i> {
    typedef T Type;

    template<typename Passed>
    T yield(Passed) {
      return T();
    }
  };
};

typedef std::string (*AnnotatedToString)(Annotation<std::string>, int);

TEST(ApplyFunctionTest, shouldCallPassedFunctionWithParametersGeneratedFromPassedType) {
  ASSERT_EQ("'' '0'", (applyFunction<DefaultValueParameters, ToString>(&toString, 0)));
  ASSERT_EQ("'foobar' '17'", (applyFunction<SpecializedParameters, ToString>(&toString, 0)));
}

TEST(ApplyFunctionTest, shouldTransformSignatureBeforeApplying) {
  ASSERT_EQ("'' '0'", (applyFunction<AnnotatedParameters, AnnotatedToString>(&toString, 0)));
}

struct MoreSpecializedParameters {
  template<typename T, int i>
  struct Parameter;

  template<int i>
  struct Parameter<std::string, i> {
    typedef std::string Type;

    template<typename Passed>
    std::string yield(std::string passed) {
      return passed;
    }
  };

  template<int i>
  struct Parameter<int, i> {
    typedef int Type;

    template<typename Passed>
    int yield(Passed) {
      return i;
    }
  };
};

TEST(ApplyFunctionTest, shouldLetParametersExamineParameterIndexAndPassedValue) {
  std::string passed = "foo";
  ASSERT_EQ("'foo' '1'", (applyFunction<MoreSpecializedParameters, ToString>(&toString, passed)));
}

struct SideEffectParameters {
  static int called;

  template<typename T, int i>
  struct Parameter {
    typedef T Type;

    template<typename Passed>
    void observe(Passed) {
      ++called;
    }
  };
};

int SideEffectParameters::called = 0;

TEST(ApplyFunctionTest, shouldYieldParametersForSideEffectsIfRequested) {
  SideEffectParameters::called = 0;
  observeFunction<SideEffectParameters, ToString>(&toString, 0);
  ASSERT_EQ(2, SideEffectParameters::called);
}

TEST(ApplyFunctionTest, shouldExposeArity) {
  ASSERT_EQ(2, (ApplyFunction<DefaultValueParameters, ToString>::arity()));
}

struct HasVoidToString {
  static std::string asString;

  static void toString(std::string s, int i) {
    std::stringstream buffer;
    buffer << "'" << s << "' '" << i << "'";
    asString = buffer.str();
  }
};

std::string HasVoidToString::asString = "";

typedef void (*VoidToString)(std::string, int);
typedef void (*AnnotatedVoidToString)(Annotation<std::string>, int);

TEST(ApplyVoidFunctionTest, shouldCallPassedVoidFunctionWithParametersGeneratedFromPassedType) {
  applyVoidFunction<DefaultValueParameters, VoidToString>(&HasVoidToString::toString, 0);
  ASSERT_EQ("'' '0'", HasVoidToString::asString);

  applyVoidFunction<SpecializedParameters, VoidToString>(&HasVoidToString::toString, 0);
  ASSERT_EQ("'foobar' '17'", HasVoidToString::asString);

  applyVoidFunction<AnnotatedParameters, AnnotatedVoidToString>(&HasVoidToString::toString, 0);
  ASSERT_EQ("'' '0'", HasVoidToString::asString);

  std::string passed = "foo";
  applyVoidFunction<MoreSpecializedParameters, VoidToString>(&HasVoidToString::toString, passed);
  ASSERT_EQ("'foo' '1'", HasVoidToString::asString);

  ASSERT_EQ(2, (ApplyVoidFunction<DefaultValueParameters, VoidToString>::arity()));
}

struct HasToString {
  std::string toString(std::string s, int i) {
    std::stringstream buffer;
    buffer << "'" << s << "' '" << i << "'";
    return buffer.str();
  }
};

typedef std::string (HasToString::* ToStringMethod)(std::string, int);
typedef std::string (HasToString::* AnnotatedToStringMethod)(Annotation<std::string>, int);

TEST(ApplyMethodTest, shouldCallPassedMethodOnReceiverWithParametersGeneratedFromPassedType) {
  HasToString hasToString;
  ASSERT_EQ("'' '0'", (applyMethod<DefaultValueParameters, ToStringMethod>(hasToString, &HasToString::toString, 0)));

  ASSERT_EQ("'foobar' '17'",
            (applyMethod<SpecializedParameters, ToStringMethod>(hasToString, &HasToString::toString, 0)));

  ASSERT_EQ("'' '0'",
            (applyMethod<AnnotatedParameters, AnnotatedToStringMethod>(hasToString, &HasToString::toString, 0)));

  std::string passed = "foo";
  ASSERT_EQ("'foo' '1'",
            (applyMethod<MoreSpecializedParameters, ToStringMethod>(hasToString, &HasToString::toString, passed)));

  SideEffectParameters::called = 0;
  observeMethod<SideEffectParameters, ToStringMethod>(&HasToString::toString, 0);
  ASSERT_EQ(2, SideEffectParameters::called);

  ASSERT_EQ(2, (ApplyMethod<DefaultValueParameters, ToStringMethod>::arity()));
}

struct ToStringer {
  std::string toString;

  ToStringer(std::string s, int i) {
    std::stringstream buffer;
    buffer << "'" << s << "' '" << i << "'";
    toString = buffer.str();
  }
};

TEST(ApplyConstructorTest, shouldCallConstructorWithParametersGeneratedFromPassedType) {
  typedef ToStringer Ctor (std::string, int);
  typedef ToStringer AnnotatedCtor (Annotation<std::string>, int);
  typedef std::allocator<int> Allocator;

  sauce::auto_ptr<ToStringer> toStringer(applyConstructor<DefaultValueParameters, Ctor, Allocator>(0));
  ASSERT_EQ("'' '0'", toStringer->toString);

  toStringer.reset(applyConstructor<SpecializedParameters, Ctor, Allocator>(0));
  ASSERT_EQ("'foobar' '17'", toStringer->toString);

  toStringer.reset(applyConstructor<AnnotatedParameters, AnnotatedCtor, Allocator>(0));
  ASSERT_EQ("'' '0'", toStringer->toString);

  std::string passed = "foo";
  toStringer.reset(applyConstructor<MoreSpecializedParameters, Ctor, Allocator>(passed));
  ASSERT_EQ("'foo' '1'", toStringer->toString);

  SideEffectParameters::called = 0;
  observeConstructor<SideEffectParameters, Ctor, Allocator>(0);
  ASSERT_EQ(2, SideEffectParameters::called);

  ASSERT_EQ(2, (ApplyConstructor<DefaultValueParameters, Ctor, Allocator>::arity()));
}

class NoArg {};

TEST(ApplyConstructorTest, shouldInterpretNakedTypesAsNoArgConstructors) {
  typedef std::allocator<int> Allocator;
  sauce::auto_ptr<NoArg> noArg(applyConstructor<DefaultValueParameters, NoArg, Allocator>(0));

  SideEffectParameters::called = 0;
  observeConstructor<SideEffectParameters, NoArg, Allocator>(0);
  ASSERT_EQ(0, SideEffectParameters::called);

  ASSERT_EQ(0, (ApplyConstructor<DefaultValueParameters, NoArg, Allocator>::arity()));
}

}
}
