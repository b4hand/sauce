#ifndef SAUCE_SAUCE_HANDLE_H_
#define SAUCE_SAUCE_HANDLE_H_

namespace sauce { namespace internal {

  template<typename T>
  class Handle;

  template<typename T>
  class Handle<T &> {

    T * t;

  public:

    Handle(T & t): t(&t) {}
    operator T &() { return *t; }

    bool operator< (const Handle<T &> other) const { return t <  other.t; }
    bool operator==(const Handle<T &> other) const { return t == other.t; }

  };

  template<typename T>
  class Handle<T *> {

    T * t;

  public:

    Handle(T * t): t(t) {}
    operator T *() { return t; }

    bool operator< (const Handle<T *> other) const { return t <  other.t; }
    bool operator==(const Handle<T *> other) const { return t == other.t; }

  };

} } // namespace internal, namespace sauce

#endif