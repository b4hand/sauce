#ifndef SAUCE_INTERNAL_TYPE_ID_H_
#define SAUCE_INTERNAL_TYPE_ID_H_

#include <sauce/exceptions.h>

namespace sauce {
namespace internal {

/**
 * An opaque, reflective value representing an arbitrary type.
 *
 * TypeIds are opaque objects that fingerprint possible requests one may make
 * to an Injector.  They are values (not types) with a total ordering.  This
 * allows us to do arbitrary binding resolution, but only at runtime.
 *
 * Concretely, they are function pointers: the total ordering is that of the
 * address space.  No RTTI (i.e. typeid) is used.
 */
typedef void (*TypeSignature)();

/**
 * The template that generates TypeSignatures.
 */
template<typename Type>
void TypeSignatureFactory() {}

/**
 * A TypeSignature equipped with specific helper methods dealing in the hidden type.
 */
class TypeId {
  TypeSignature signature;

  TypeId():
    signature(NULL) {}

protected:

  TypeId(TypeSignature const & signature):
    signature(signature) {}

public:

  bool operator==(TypeId const & id) const {
    return signature == id.signature;
  }

  bool operator!=(TypeId const & id) const {
    return signature != id.signature;
  }

  bool operator<(TypeId const & id) const {
    return signature < id.signature;
  }

  /**
   * Throw an OutOfScopeException appropriate for the hidden type, assuming it is a Scope.
   */
  virtual void throwOutOfScopeException() const {
    throw OutOfScopeException();
  }
};

template<typename Type>
TypeId typeIdOf();

/**
 * The TypeId derived class that acknowledges the hidden type.
 */
template<typename Type>
class ResolvedTypeId: public TypeId {
  friend TypeId typeIdOf<Type>();

  ResolvedTypeId():
    TypeId(&TypeSignatureFactory<Type>) {}

public:

  void throwOutOfScopeException() const {
    throw OutOfScopeExceptionFor<Type>();
  }
};

/**
 * How one gets TypeIds.
 */
template<typename Type>
TypeId typeIdOf() {
  return ResolvedTypeId<Type>();
}

/**
 * A set of type ids.
 */
typedef std::set<TypeId> TypeIds;

}

namespace i = ::sauce::internal;

}

#endif // SAUCE_INTERNAL_TYPE_ID_H_
