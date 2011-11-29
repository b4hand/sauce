#ifndef SAUCE_INTERNAL_INJECTION_BINDING_H_
#define SAUCE_INTERNAL_INJECTION_BINDING_H_

#include <sauce/internal/resolved_binding.h>

namespace sauce {
namespace internal {

/**
 * A binding that uses an Injection to satisfy dependencies.
 */
template<typename Dependency, typename Scope>
struct InjectionBinding: public ResolvedBinding<Dependency> {};

}

namespace i = ::sauce::internal;

}

#endif // SAUCE_INTERNAL_INJECTION_BINDING_H_