// This file was GENERATED by command:
//     pump.py generated_bindings.h.pump
// DO NOT EDIT BY HAND!!!


#ifndef SAUCE_SAUCE_INTERNAL_GENERATED_BINDINGS_H_
#define SAUCE_SAUCE_INTERNAL_GENERATED_BINDINGS_H_

namespace sauce { namespace internal {

  template<typename Injector, typename F>
  struct NewBinding;

  template<typename Injector, typename Dependency>
  struct NewBinding<Injector, Dependency()> {
    static Dependency & provide(Injector & injector) {
      return *new Dependency();
    };
  };

  template<typename Injector, typename Dependency, typename A1>
  struct NewBinding<Injector, Dependency(A1)> {
    static Dependency & provide(Injector & injector) {
      return *new Dependency(injector.template provide<A1>());
    };
  };

  template<typename Injector, typename Dependency, typename A1, typename A2>
  struct NewBinding<Injector, Dependency(A1, A2)> {
    static Dependency & provide(Injector & injector) {
      return *new Dependency(injector.template provide<A1>(),
          injector.template provide<A2>());
    };
  };

} } // namespace internal, namespace sauce

#endif
