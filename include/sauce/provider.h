#ifndef SAUCE_SAUCE_PROVIDER_H_
#define SAUCE_SAUCE_PROVIDER_H_

#include <cassert>

#include <sauce/memory.h>
#include <sauce/internal/disposal_deleter.h>
#include <sauce/internal/key.h>

namespace sauce {

class Injector;

template<typename Dependency>
class Provider;

namespace internal {

/**
 * A friend of the Provider base type.
 *
 * Enables inheritors to give a Provider its own smart pointer.
 */
struct ProviderFriend {
  template<typename ProvidedDependency, typename Name>
  void setSelf(typename Key<Named<Provider<ProvidedDependency>, Name> >::Ptr ptr) const {
    ptr->setSelf(ptr);
  }
};

}

/**
 * An interface for including custom factories in an Injector.
 */
template<typename Dependency>
class Provider {

  typedef typename i::Key<Dependency>::Iface Iface;

  friend class ::sauce::internal::ProviderFriend;

  sauce::weak_ptr<Provider<Dependency> > weak;
  void setSelf(sauce::shared_ptr<Provider<Dependency> > shared) {
    assert(shared.get() == this);
    weak = shared;
  }

protected:

  sauce::shared_ptr<Provider<Dependency> > getSelf() const {
    sauce::shared_ptr<Provider<Dependency> > self = weak.lock();
    assert(self.get() == this);
    return self;
  }

public:

  Provider():
    weak() {}

  /**
   * Provide an Iface.
   */
  virtual sauce::shared_ptr<Iface> get() = 0;

};

/**
 * An interface for including custom factories in an Injector.
 */
template<typename Dependency>
class AbstractProvider: public Provider<Dependency> {

  typedef typename i::Key<Dependency>::Iface Iface;
  typedef sauce::shared_ptr<Provider<Dependency> > ProviderPtr;
  typedef AbstractProvider<Dependency> Naked;
  typedef sauce::shared_ptr<Naked> NakedPtr;

  /**
   * Create a shared pointer deleter suitable for this provider.
   */
  i::DisposalDeleter<Iface, Naked> deleter() const {
    ProviderPtr provider = this->getSelf();
    NakedPtr naked = sauce::static_pointer_cast<Naked>(provider);
    i::DisposalDeleter<Iface, Naked> deleter(naked);
    return deleter;
  }

public:

  AbstractProvider():
    Provider<Dependency>() {}

  /**
   * Provide an Iface.
   *
   * A naked instance pointer is obtained with provide(), and wrapped in a shared_ptr.  It is also
   * given a custom deleter, to dispose of the naked pointer with dispose(Iface *).
   */
  sauce::shared_ptr<Iface> get() {
    sauce::shared_ptr<Iface> provided(provide(), deleter());
    return provided;
  }

  /**
   * Provide a naked Iface pointer.
   */
  virtual Iface * provide() = 0;

  /**
   * Dispose of an Iface provided by this provider.
   */
  virtual void dispose(Iface *) = 0;

};

}

#endif // SAUCE_SAUCE_PROVIDER_H_
