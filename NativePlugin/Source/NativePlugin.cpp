#include "IUnityLog.h"

#include <iostream>
#include <string>

using namespace std;

static IUnityLog* mLogger;

extern "C" void UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API SendDataFromUnity(float t)
{
	string content = "Native log: " + to_string(t);
	UNITY_LOG(mLogger, content.c_str());
}

extern "C" void UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API UnityPluginLoad(IUnityInterfaces * pInterfaces)
{
	mLogger = pInterfaces->Get<IUnityLog>();
	UNITY_LOG(mLogger, "Native Plugin load");
}
extern "C" void UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API UnityPluginUnload()
{
	UNITY_LOG(mLogger, "Native Plugin unload");
	mLogger = nullptr;
}