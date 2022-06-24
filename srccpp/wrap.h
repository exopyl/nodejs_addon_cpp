#include <napi.h>
#include "animals.h"

// class
class Dog : public Napi::ObjectWrap<Dog> {
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  Dog(const Napi::CallbackInfo &info);
  ~Dog();

private:
  // reference to store the class definition that needs to be exported to JS
  static Napi::FunctionReference constructor;

  Napi::Value Speak(const Napi::CallbackInfo &info);

  CDog* m_pDog = nullptr;
};

// function
namespace functionHello {
  std::string hello();
  Napi::String HelloWrapped(const Napi::CallbackInfo& info);
  Napi::Object Init(Napi::Env env, Napi::Object exports);
}