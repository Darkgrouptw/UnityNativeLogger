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
		StartCoroutine(Timer());
	}

	private IEnumerator Timer()
	{
		while (true)
		{
			yield return new WaitForEndOfFrame();
			SendDataFromUnityToLog(Time.timeSinceLevelLoad);
		}
	}
}
