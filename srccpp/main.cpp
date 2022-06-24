#include <napi.h>
#include "wrap.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  Dog::Init(env, exports);
  functionHello::Init(env, exports);

  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, InitAll)
