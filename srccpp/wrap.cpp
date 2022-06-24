#include "wrap.h"

/**
 *  Class Initilisation
 */
Napi::Object Dog::Init(Napi::Env env, Napi::Object exports)
{
  Napi::HandleScope scope(env);

  Napi::Function func = DefineClass(env, "Dog", {
    InstanceMethod("Speak", &Dog::Speak),
  });

  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("Dog", func);
  return exports;
}

/**
 *  Constructor
 */
Napi::FunctionReference Dog::constructor;
Dog::Dog(const Napi::CallbackInfo& info) : Napi::ObjectWrap<Dog>(info)
{
    m_pDog = new CDog();
}

/**
 *  Destructor
 */
Dog::~Dog()
{
    delete m_pDog;
}

/**
 *  Methods
 */
Napi::Value Dog::Speak(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  return Napi::String::New(env, m_pDog->Speak());
}



/**
 *  Functions
 */
 std::string functionHello::hello()
 {
  return "Hello World";
}
Napi::String functionHello::HelloWrapped(const Napi::CallbackInfo& info) 
{
  Napi::Env env = info.Env();
  Napi::String returnValue = Napi::String::New(env, functionHello::hello());
  
  return returnValue;
}
Napi::Object functionHello::Init(Napi::Env env, Napi::Object exports) 
{
  exports.Set(
    "hello", Napi::Function::New(env, functionHello::HelloWrapped)
  );
 
  return exports;
}