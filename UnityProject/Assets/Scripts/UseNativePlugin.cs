using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Runtime.InteropServices;

public class UseNativePlugin : MonoBehaviour
{
	[DllImport("NativePlugin")]
	private static extern void SendDataFromUnityToLog(float _);

	private void Start()
	{
		UnityEngine.Random.InitState(System.DateTime.Now.Second);
		float randNum = UnityEngine.Random.value;
		Debug.Log("Unity Log: " + randNum.ToString());

		SendDataFromUnityToLog(randNum);
	}
}
