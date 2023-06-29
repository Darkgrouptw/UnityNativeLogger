#include "IUnityLog.h"

#include <iostream>
#include <string>

using namespace std;

static IUnityLog* mLogger;

extern "C" void UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API SendDataFromUnityToLog(float t)
{
	string content = "Native log: " + to_string(t);
	const char* c_content = content.c_str();
	UNITY_LOG(mLogger, c_content);
	UNITY_LOG_WARNING(mLogger, c_content);
	UNITY_LOG_ERROR(mLogger, c_content);
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