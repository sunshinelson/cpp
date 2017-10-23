// NativeFunctions.cpp: Definiert die exportierten Funktionen für die DLL-Anwendung.
//

#include "stdafx.h"
#include "Test.h"
#include "iostream"

/*
* Class:     Test
* Method:    display
* Signature: ()V
*/
JNIEXPORT void JNICALL Java_Test_display
(JNIEnv *, jclass) {
	std::cout << "Ola chica"<<std::endl;

}

/*
* Class:     Test
* Method:    increment
* Signature: (I)I
*/
JNIEXPORT jint JNICALL Java_Test_increment
(JNIEnv *, jclass, jint i) {
	return ++i;
}


