// dllmain.cpp : Definiert den Einstiegspunkt für die DLL-Anwendung.
#include "stdafx.h"
#include "Test.h"
#include <iostream>
using namespace std;
/*
* Class:     Test
* Method:    display
* Signature: ()V
*/
JNIEXPORT void JNICALL Java_Test_display(JNIEnv *, jclass) {
	cout << "hello there" << endl;
}

/*
* Class:     Test
* Method:    increment
* Signature: (I)I
*/
JNIEXPORT jint JNICALL Java_Test_increment(JNIEnv *, jclass, jint i) {
	return ++i;
}


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

