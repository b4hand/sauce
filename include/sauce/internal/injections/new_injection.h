// This file was GENERATED by command:
//     pump.py new_injection.h.pump
// DO NOT EDIT BY HAND!!!

#ifndef SAUCE_INTERNAL_INJECTIONS_NEW_INJECTION_H_
#define SAUCE_INTERNAL_INJECTIONS_NEW_INJECTION_H_

#include <sauce/injector.h>
#include <sauce/memory.h>
#include <sauce/named.h>
#include <sauce/provider.h>
#include <sauce/internal/injection_binding.h>
#include <sauce/internal/injections/injection.h>
#include <sauce/internal/key.h>
#include <sauce/internal/type_id.h>

namespace sauce {
namespace internal {
namespace injections {

template<typename Dependency, typename Constructor, typename Allocator>
class NewInjection;

template<typename Dependency, typename Impl, typename Allocator>
class NewInjection<Dependency, Impl(), Allocator>:
  public Injection<Dependency> {

  typedef typename Key<Dependency>::Iface Iface;
  typedef typename Key<Dependency>::Ptr Ptr;
  typedef typename Allocator::template rebind<Impl>::other ImplAllocator;
  typedef NewInjection<Dependency, Impl(), Allocator> New;
  typedef DisposalDeleter<Iface, New> Deleter;

  friend class DisposalDeleter<Iface, New>;

  mutable ImplAllocator allocator;

public:

  typedef typename Injection<Dependency>::InjectionPtr InjectionPtr;

  /**
   * Provide an Iface.
   *
   * A naked instance pointer is allocated and wrapped in a shared_ptr.  It is
   * also given a custom deleter, to dispose of the naked pointer with
   * dispose(Iface *).
   */
 Ptr provide(InjectionPtr injection, InjectorPtr) const {
    Deleter deleter(sauce::static_pointer_cast<New>(injection));
    Impl * impl = allocator.allocate(1);
    Ptr provided(new(impl) Impl(), deleter);
    return provided;
  }

  void dispose(Iface * iface) const {
    Impl * impl = static_cast<Impl *>(iface);
    impl->~Impl(); // Must not throw
    allocator.deallocate(impl, 1);
  }
};

template<typename Dependency, typename Impl, typename Allocator, typename A1>
class NewInjection<Dependency, Impl(A1), Allocator>:
  public Injection<Dependency> {

  typedef typename Key<Dependency>::Iface Iface;
  typedef typename Key<Dependency>::Ptr Ptr;
  typedef typename Allocator::template rebind<Impl>::other ImplAllocator;
  typedef NewInjection<Dependency, Impl(A1), Allocator> New;
  typedef DisposalDeleter<Iface, New> Deleter;

  friend class DisposalDeleter<Iface, New>;

  mutable ImplAllocator allocator;

public:

  typedef typename Injection<Dependency>::InjectionPtr InjectionPtr;

  /**
   * Provide an Iface.
   *
   * A naked instance pointer is allocated and wrapped in a shared_ptr.  It is
   * also given a custom deleter, to dispose of the naked pointer with
   * dispose(Iface *).
   */
 Ptr provide(InjectionPtr injection, InjectorPtr injector) const {
    typename Key<A1>::Ptr a1(this->template getHelper<A1>(injector));
    Deleter deleter(sauce::static_pointer_cast<New>(injection));
    Impl * impl = allocator.allocate(1);
    Ptr provided(new(impl) Impl(a1), deleter);
    return provided;
  }

  void validateAcyclic(InjectorPtr injector, TypeIds & ids) const {
    this->template validateAcyclicHelper<A1>(injector, ids);
  }

  void dispose(Iface * iface) const {
    Impl * impl = static_cast<Impl *>(iface);
    impl->~Impl(); // Must not throw
    allocator.deallocate(impl, 1);
  }
};

template<typename Dependency, typename Impl, typename Allocator, typename A1,
    typename A2>
class NewInjection<Dependency, Impl(A1, A2), Allocator>:
  public Injection<Dependency> {

  typedef typename Key<Dependency>::Iface Iface;
  typedef typename Key<Dependency>::Ptr Ptr;
  typedef typename Allocator::template rebind<Impl>::other ImplAllocator;
  typedef NewInjection<Dependency, Impl(A1, A2), Allocator> New;
  typedef DisposalDeleter<Iface, New> Deleter;

  friend class DisposalDeleter<Iface, New>;

  mutable ImplAllocator allocator;

public:

  typedef typename Injection<Dependency>::InjectionPtr InjectionPtr;

  /**
   * Provide an Iface.
   *
   * A naked instance pointer is allocated and wrapped in a shared_ptr.  It is
   * also given a custom deleter, to dispose of the naked pointer with
   * dispose(Iface *).
   */
 Ptr provide(InjectionPtr injection, InjectorPtr injector) const {
    typename Key<A1>::Ptr a1(this->template getHelper<A1>(injector));
    typename Key<A2>::Ptr a2(this->template getHelper<A2>(injector));
    Deleter deleter(sauce::static_pointer_cast<New>(injection));
    Impl * impl = allocator.allocate(1);
    Ptr provided(new(impl) Impl(a1, a2), deleter);
    return provided;
  }

  void validateAcyclic(InjectorPtr injector, TypeIds & ids) const {
    this->template validateAcyclicHelper<A1>(injector, ids);
    this->template validateAcyclicHelper<A2>(injector, ids);
  }

  void dispose(Iface * iface) const {
    Impl * impl = static_cast<Impl *>(iface);
    impl->~Impl(); // Must not throw
    allocator.deallocate(impl, 1);
  }
};

template<typename Dependency, typename Impl, typename Allocator, typename A1,
    typename A2, typename A3>
class NewInjection<Dependency, Impl(A1, A2, A3), Allocator>:
  public Injection<Dependency> {

  typedef typename Key<Dependency>::Iface Iface;
  typedef typename Key<Dependency>::Ptr Ptr;
  typedef typename Allocator::template rebind<Impl>::other ImplAllocator;
  typedef NewInjection<Dependency, Impl(A1, A2, A3), Allocator> New;
  typedef DisposalDeleter<Iface, New> Deleter;

  friend class DisposalDeleter<Iface, New>;

  mutable ImplAllocator allocator;

public:

  typedef typename Injection<Dependency>::InjectionPtr InjectionPtr;

  /**
   * Provide an Iface.
   *
   * A naked instance pointer is allocated and wrapped in a shared_ptr.  It is
   * also given a custom deleter, to dispose of the naked pointer with
   * dispose(Iface *).
   */
 Ptr provide(InjectionPtr injection, InjectorPtr injector) const {
    typename Key<A1>::Ptr a1(this->template getHelper<A1>(injector));
    typename Key<A2>::Ptr a2(this->template getHelper<A2>(injector));
    typename Key<A3>::Ptr a3(this->template getHelper<A3>(injector));
    Deleter deleter(sauce::static_pointer_cast<New>(injection));
    Impl * impl = allocator.allocate(1);
    Ptr provided(new(impl) Impl(a1, a2, a3), deleter);
    return provided;
  }

  void validateAcyclic(InjectorPtr injector, TypeIds & ids) const {
    this->template validateAcyclicHelper<A1>(injector, ids);
    this->template validateAcyclicHelper<A2>(injector, ids);
    this->template validateAcyclicHelper<A3>(injector, ids);
  }

  void dispose(Iface * iface) const {
    Impl * impl = static_cast<Impl *>(iface);
    impl->~Impl(); // Must not throw
    allocator.deallocate(impl, 1);
  }
};

template<typename Dependency, typename Impl, typename Allocator, typename A1,
    typename A2, typename A3, typename A4>
class NewInjection<Dependency, Impl(A1, A2, A3, A4), Allocator>:
  public Injection<Dependency> {

  typedef typename Key<Dependency>::Iface Iface;
  typedef typename Key<Dependency>::Ptr Ptr;
  typedef typename Allocator::template rebind<Impl>::other ImplAllocator;
  typedef NewInjection<Dependency, Impl(A1, A2, A3, A4), Allocator> New;
  typedef DisposalDeleter<Iface, New> Deleter;

  friend class DisposalDeleter<Iface, New>;

  mutable ImplAllocator allocator;

public:

  typedef typename Injection<Dependency>::InjectionPtr InjectionPtr;

  /**
   * Provide an Iface.
   *
   * A naked instance pointer is allocated and wrapped in a shared_ptr.  It is
   * also given a custom deleter, to dispose of the naked pointer with
   * dispose(Iface *).
   */
 Ptr provide(InjectionPtr injection, InjectorPtr injector) const {
    typename Key<A1>::Ptr a1(this->template getHelper<A1>(injector));
    typename Key<A2>::Ptr a2(this->template getHelper<A2>(injector));
    typename Key<A3>::Ptr a3(this->template getHelper<A3>(injector));
    typename Key<A4>::Ptr a4(this->template getHelper<A4>(injector));
    Deleter deleter(sauce::static_pointer_cast<New>(injection));
    Impl * impl = allocator.allocate(1);
    Ptr provided(new(impl) Impl(a1, a2, a3, a4), deleter);
    return provided;
  }

  void validateAcyclic(InjectorPtr injector, TypeIds & ids) const {
    this->template validateAcyclicHelper<A1>(injector, ids);
    this->template validateAcyclicHelper<A2>(injector, ids);
    this->template validateAcyclicHelper<A3>(injector, ids);
    this->template validateAcyclicHelper<A4>(injector, ids);
  }

  void dispose(Iface * iface) const {
    Impl * impl = static_cast<Impl *>(iface);
    impl->~Impl(); // Must not throw
    allocator.deallocate(impl, 1);
  }
};

template<typename Dependency, typename Impl, typename Allocator, typename A1,
    typename A2, typename A3, typename A4, typename A5>
class NewInjection<Dependency, Impl(A1, A2, A3, A4, A5), Allocator>:
  public Injection<Dependency> {

  typedef typename Key<Dependency>::Iface Iface;
  typedef typename Key<Dependency>::Ptr Ptr;
  typedef typename Allocator::template rebind<Impl>::other ImplAllocator;
  typedef NewInjection<Dependency, Impl(A1, A2, A3, A4, A5), Allocator> New;
  typedef DisposalDeleter<Iface, New> Deleter;

  friend class DisposalDeleter<Iface, New>;

  mutable ImplAllocator allocator;

public:

  typedef typename Injection<Dependency>::InjectionPtr InjectionPtr;

  /**
   * Provide an Iface.
   *
   * A naked instance pointer is allocated and wrapped in a shared_ptr.  It is
   * also given a custom deleter, to dispose of the naked pointer with
   * dispose(Iface *).
   */
 Ptr provide(InjectionPtr injection, InjectorPtr injector) const {
    typename Key<A1>::Ptr a1(this->template getHelper<A1>(injector));
    typename Key<A2>::Ptr a2(this->template getHelper<A2>(injector));
    typename Key<A3>::Ptr a3(this->template getHelper<A3>(injector));
    typename Key<A4>::Ptr a4(this->template getHelper<A4>(injector));
    typename Key<A5>::Ptr a5(this->template getHelper<A5>(injector));
    Deleter deleter(sauce::static_pointer_cast<New>(injection));
    Impl * impl = allocator.allocate(1);
    Ptr provided(new(impl) Impl(a1, a2, a3, a4, a5), deleter);
    return provided;
  }

  void validateAcyclic(InjectorPtr injector, TypeIds & ids) const {
    this->template validateAcyclicHelper<A1>(injector, ids);
    this->template validateAcyclicHelper<A2>(injector, ids);
    this->template validateAcyclicHelper<A3>(injector, ids);
    this->template validateAcyclicHelper<A4>(injector, ids);
    this->template validateAcyclicHelper<A5>(injector, ids);
  }

  void dispose(Iface * iface) const {
    Impl * impl = static_cast<Impl *>(iface);
    impl->~Impl(); // Must not throw
    allocator.deallocate(impl, 1);
  }
};

template<typename Dependency, typename Impl, typename Allocator, typename A1,
    typename A2, typename A3, typename A4, typename A5, typename A6>
class NewInjection<Dependency, Impl(A1, A2, A3, A4, A5, A6), Allocator>:
  public Injection<Dependency> {

  typedef typename Key<Dependency>::Iface Iface;
  typedef typename Key<Dependency>::Ptr Ptr;
  typedef typename Allocator::template rebind<Impl>::other ImplAllocator;
  typedef NewInjection<Dependency, Impl(A1, A2, A3, A4, A5, A6), Allocator> New;
  typedef DisposalDeleter<Iface, New> Deleter;

  friend class DisposalDeleter<Iface, New>;

  mutable ImplAllocator allocator;

public:

  typedef typename Injection<Dependency>::InjectionPtr InjectionPtr;

  /**
   * Provide an Iface.
   *
   * A naked instance pointer is allocated and wrapped in a shared_ptr.  It is
   * also given a custom deleter, to dispose of the naked pointer with
   * dispose(Iface *).
   */
 Ptr provide(InjectionPtr injection, InjectorPtr injector) const {
    typename Key<A1>::Ptr a1(this->template getHelper<A1>(injector));
    typename Key<A2>::Ptr a2(this->template getHelper<A2>(injector));
    typename Key<A3>::Ptr a3(this->template getHelper<A3>(injector));
    typename Key<A4>::Ptr a4(this->template getHelper<A4>(injector));
    typename Key<A5>::Ptr a5(this->template getHelper<A5>(injector));
    typename Key<A6>::Ptr a6(this->template getHelper<A6>(injector));
    Deleter deleter(sauce::static_pointer_cast<New>(injection));
    Impl * impl = allocator.allocate(1);
    Ptr provided(new(impl) Impl(a1, a2, a3, a4, a5, a6), deleter);
    return provided;
  }

  void validateAcyclic(InjectorPtr injector, TypeIds & ids) const {
    this->template validateAcyclicHelper<A1>(injector, ids);
    this->template validateAcyclicHelper<A2>(injector, ids);
    this->template validateAcyclicHelper<A3>(injector, ids);
    this->template validateAcyclicHelper<A4>(injector, ids);
    this->template validateAcyclicHelper<A5>(injector, ids);
    this->template validateAcyclicHelper<A6>(injector, ids);
  }

  void dispose(Iface * iface) const {
    Impl * impl = static_cast<Impl *>(iface);
    impl->~Impl(); // Must not throw
    allocator.deallocate(impl, 1);
  }
};

template<typename Dependency, typename Impl, typename Allocator, typename A1,
    typename A2, typename A3, typename A4, typename A5, typename A6,
    typename A7>
class NewInjection<Dependency, Impl(A1, A2, A3, A4, A5, A6, A7), Allocator>:
  public Injection<Dependency> {

  typedef typename Key<Dependency>::Iface Iface;
  typedef typename Key<Dependency>::Ptr Ptr;
  typedef typename Allocator::template rebind<Impl>::other ImplAllocator;
  typedef NewInjection<Dependency, Impl(A1, A2, A3, A4, A5, A6, A7),
      Allocator> New;
  typedef DisposalDeleter<Iface, New> Deleter;

  friend class DisposalDeleter<Iface, New>;

  mutable ImplAllocator allocator;

public:

  typedef typename Injection<Dependency>::InjectionPtr InjectionPtr;

  /**
   * Provide an Iface.
   *
   * A naked instance pointer is allocated and wrapped in a shared_ptr.  It is
   * also given a custom deleter, to dispose of the naked pointer with
   * dispose(Iface *).
   */
 Ptr provide(InjectionPtr injection, InjectorPtr injector) const {
    typename Key<A1>::Ptr a1(this->template getHelper<A1>(injector));
    typename Key<A2>::Ptr a2(this->template getHelper<A2>(injector));
    typename Key<A3>::Ptr a3(this->template getHelper<A3>(injector));
    typename Key<A4>::Ptr a4(this->template getHelper<A4>(injector));
    typename Key<A5>::Ptr a5(this->template getHelper<A5>(injector));
    typename Key<A6>::Ptr a6(this->template getHelper<A6>(injector));
    typename Key<A7>::Ptr a7(this->template getHelper<A7>(injector));
    Deleter deleter(sauce::static_pointer_cast<New>(injection));
    Impl * impl = allocator.allocate(1);
    Ptr provided(new(impl) Impl(a1, a2, a3, a4, a5, a6, a7), deleter);
    return provided;
  }

  void validateAcyclic(InjectorPtr injector, TypeIds & ids) const {
    this->template validateAcyclicHelper<A1>(injector, ids);
    this->template validateAcyclicHelper<A2>(injector, ids);
    this->template validateAcyclicHelper<A3>(injector, ids);
    this->template validateAcyclicHelper<A4>(injector, ids);
    this->template validateAcyclicHelper<A5>(injector, ids);
    this->template validateAcyclicHelper<A6>(injector, ids);
    this->template validateAcyclicHelper<A7>(injector, ids);
  }

  void dispose(Iface * iface) const {
    Impl * impl = static_cast<Impl *>(iface);
    impl->~Impl(); // Must not throw
    allocator.deallocate(impl, 1);
  }
};

template<typename Dependency, typename Impl, typename Allocator, typename A1,
    typename A2, typename A3, typename A4, typename A5, typename A6,
    typename A7, typename A8>
class NewInjection<Dependency, Impl(A1, A2, A3, A4, A5, A6, A7, A8), Allocator>:
  public Injection<Dependency> {

  typedef typename Key<Dependency>::Iface Iface;
  typedef typename Key<Dependency>::Ptr Ptr;
  typedef typename Allocator::template rebind<Impl>::other ImplAllocator;
  typedef NewInjection<Dependency, Impl(A1, A2, A3, A4, A5, A6, A7, A8),
      Allocator> New;
  typedef DisposalDeleter<Iface, New> Deleter;

  friend class DisposalDeleter<Iface, New>;

  mutable ImplAllocator allocator;

public:

  typedef typename Injection<Dependency>::InjectionPtr InjectionPtr;

  /**
   * Provide an Iface.
   *
   * A naked instance pointer is allocated and wrapped in a shared_ptr.  It is
   * also given a custom deleter, to dispose of the naked pointer with
   * dispose(Iface *).
   */
 Ptr provide(InjectionPtr injection, InjectorPtr injector) const {
    typename Key<A1>::Ptr a1(this->template getHelper<A1>(injector));
    typename Key<A2>::Ptr a2(this->template getHelper<A2>(injector));
    typename Key<A3>::Ptr a3(this->template getHelper<A3>(injector));
    typename Key<A4>::Ptr a4(this->template getHelper<A4>(injector));
    typename Key<A5>::Ptr a5(this->template getHelper<A5>(injector));
    typename Key<A6>::Ptr a6(this->template getHelper<A6>(injector));
    typename Key<A7>::Ptr a7(this->template getHelper<A7>(injector));
    typename Key<A8>::Ptr a8(this->template getHelper<A8>(injector));
    Deleter deleter(sauce::static_pointer_cast<New>(injection));
    Impl * impl = allocator.allocate(1);
    Ptr provided(new(impl) Impl(a1, a2, a3, a4, a5, a6, a7, a8), deleter);
    return provided;
  }

  void validateAcyclic(InjectorPtr injector, TypeIds & ids) const {
    this->template validateAcyclicHelper<A1>(injector, ids);
    this->template validateAcyclicHelper<A2>(injector, ids);
    this->template validateAcyclicHelper<A3>(injector, ids);
    this->template validateAcyclicHelper<A4>(injector, ids);
    this->template validateAcyclicHelper<A5>(injector, ids);
    this->template validateAcyclicHelper<A6>(injector, ids);
    this->template validateAcyclicHelper<A7>(injector, ids);
    this->template validateAcyclicHelper<A8>(injector, ids);
  }

  void dispose(Iface * iface) const {
    Impl * impl = static_cast<Impl *>(iface);
    impl->~Impl(); // Must not throw
    allocator.deallocate(impl, 1);
  }
};

template<typename Dependency, typename Impl, typename Allocator, typename A1,
    typename A2, typename A3, typename A4, typename A5, typename A6,
    typename A7, typename A8, typename A9>
class NewInjection<Dependency, Impl(A1, A2, A3, A4, A5, A6, A7, A8, A9),
    Allocator>:
  public Injection<Dependency> {

  typedef typename Key<Dependency>::Iface Iface;
  typedef typename Key<Dependency>::Ptr Ptr;
  typedef typename Allocator::template rebind<Impl>::other ImplAllocator;
  typedef NewInjection<Dependency, Impl(A1, A2, A3, A4, A5, A6, A7, A8, A9),
      Allocator> New;
  typedef DisposalDeleter<Iface, New> Deleter;

  friend class DisposalDeleter<Iface, New>;

  mutable ImplAllocator allocator;

public:

  typedef typename Injection<Dependency>::InjectionPtr InjectionPtr;

  /**
   * Provide an Iface.
   *
   * A naked instance pointer is allocated and wrapped in a shared_ptr.  It is
   * also given a custom deleter, to dispose of the naked pointer with
   * dispose(Iface *).
   */
 Ptr provide(InjectionPtr injection, InjectorPtr injector) const {
    typename Key<A1>::Ptr a1(this->template getHelper<A1>(injector));
    typename Key<A2>::Ptr a2(this->template getHelper<A2>(injector));
    typename Key<A3>::Ptr a3(this->template getHelper<A3>(injector));
    typename Key<A4>::Ptr a4(this->template getHelper<A4>(injector));
    typename Key<A5>::Ptr a5(this->template getHelper<A5>(injector));
    typename Key<A6>::Ptr a6(this->template getHelper<A6>(injector));
    typename Key<A7>::Ptr a7(this->template getHelper<A7>(injector));
    typename Key<A8>::Ptr a8(this->template getHelper<A8>(injector));
    typename Key<A9>::Ptr a9(this->template getHelper<A9>(injector));
    Deleter deleter(sauce::static_pointer_cast<New>(injection));
    Impl * impl = allocator.allocate(1);
    Ptr provided(new(impl) Impl(a1, a2, a3, a4, a5, a6, a7, a8, a9), deleter);
    return provided;
  }

  void validateAcyclic(InjectorPtr injector, TypeIds & ids) const {
    this->template validateAcyclicHelper<A1>(injector, ids);
    this->template validateAcyclicHelper<A2>(injector, ids);
    this->template validateAcyclicHelper<A3>(injector, ids);
    this->template validateAcyclicHelper<A4>(injector, ids);
    this->template validateAcyclicHelper<A5>(injector, ids);
    this->template validateAcyclicHelper<A6>(injector, ids);
    this->template validateAcyclicHelper<A7>(injector, ids);
    this->template validateAcyclicHelper<A8>(injector, ids);
    this->template validateAcyclicHelper<A9>(injector, ids);
  }

  void dispose(Iface * iface) const {
    Impl * impl = static_cast<Impl *>(iface);
    impl->~Impl(); // Must not throw
    allocator.deallocate(impl, 1);
  }
};

template<typename Dependency, typename Impl, typename Allocator, typename A1,
    typename A2, typename A3, typename A4, typename A5, typename A6,
    typename A7, typename A8, typename A9, typename A10>
class NewInjection<Dependency, Impl(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10),
    Allocator>:
  public Injection<Dependency> {

  typedef typename Key<Dependency>::Iface Iface;
  typedef typename Key<Dependency>::Ptr Ptr;
  typedef typename Allocator::template rebind<Impl>::other ImplAllocator;
  typedef NewInjection<Dependency, Impl(A1, A2, A3, A4, A5, A6, A7, A8, A9,
      A10), Allocator> New;
  typedef DisposalDeleter<Iface, New> Deleter;

  friend class DisposalDeleter<Iface, New>;

  mutable ImplAllocator allocator;

public:

  typedef typename Injection<Dependency>::InjectionPtr InjectionPtr;

  /**
   * Provide an Iface.
   *
   * A naked instance pointer is allocated and wrapped in a shared_ptr.  It is
   * also given a custom deleter, to dispose of the naked pointer with
   * dispose(Iface *).
   */
 Ptr provide(InjectionPtr injection, InjectorPtr injector) const {
    typename Key<A1>::Ptr a1(this->template getHelper<A1>(injector));
    typename Key<A2>::Ptr a2(this->template getHelper<A2>(injector));
    typename Key<A3>::Ptr a3(this->template getHelper<A3>(injector));
    typename Key<A4>::Ptr a4(this->template getHelper<A4>(injector));
    typename Key<A5>::Ptr a5(this->template getHelper<A5>(injector));
    typename Key<A6>::Ptr a6(this->template getHelper<A6>(injector));
    typename Key<A7>::Ptr a7(this->template getHelper<A7>(injector));
    typename Key<A8>::Ptr a8(this->template getHelper<A8>(injector));
    typename Key<A9>::Ptr a9(this->template getHelper<A9>(injector));
    typename Key<A10>::Ptr a10(this->template getHelper<A10>(injector));
    Deleter deleter(sauce::static_pointer_cast<New>(injection));
    Impl * impl = allocator.allocate(1);
    Ptr provided(new(impl) Impl(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10),
        deleter);
    return provided;
  }

  void validateAcyclic(InjectorPtr injector, TypeIds & ids) const {
    this->template validateAcyclicHelper<A1>(injector, ids);
    this->template validateAcyclicHelper<A2>(injector, ids);
    this->template validateAcyclicHelper<A3>(injector, ids);
    this->template validateAcyclicHelper<A4>(injector, ids);
    this->template validateAcyclicHelper<A5>(injector, ids);
    this->template validateAcyclicHelper<A6>(injector, ids);
    this->template validateAcyclicHelper<A7>(injector, ids);
    this->template validateAcyclicHelper<A8>(injector, ids);
    this->template validateAcyclicHelper<A9>(injector, ids);
    this->template validateAcyclicHelper<A10>(injector, ids);
  }

  void dispose(Iface * iface) const {
    Impl * impl = static_cast<Impl *>(iface);
    impl->~Impl(); // Must not throw
    allocator.deallocate(impl, 1);
  }
};

}
}

namespace i = ::sauce::internal;
namespace inj = ::sauce::internal::injections;

}

#endif // SAUCE_INTERNAL_INJECTIONS_NEW_INJECTION_H_
