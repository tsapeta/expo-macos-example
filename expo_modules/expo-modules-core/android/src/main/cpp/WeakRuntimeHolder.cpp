#include "WeakRuntimeHolder.h"
#include "JavaScriptRuntime.h"
#include "JSIInteropModuleRegistry.h"

namespace expo {
WeakRuntimeHolder::WeakRuntimeHolder(std::weak_ptr<JavaScriptRuntime> runtime)
  : std::weak_ptr<JavaScriptRuntime>(std::move(runtime)) {}

jsi::Runtime &WeakRuntimeHolder::getJSRuntime() {
  auto runtime = lock();
  assert((runtime != nullptr) && "JS Runtime was used after deallocation");
  return runtime->get();
}

void WeakRuntimeHolder::ensureRuntimeIsValid() {
  assert((!expired()) && "JS Runtime was used after deallocation");
}

JSIInteropModuleRegistry *WeakRuntimeHolder::getModuleRegistry() {
  auto runtime = lock();
  assert((runtime != nullptr) && "JS Runtime was used after deallocation");
  return runtime->getModuleRegistry();
}
} // namespace expo
