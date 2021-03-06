// NativeMatrixFunctions.cpp: Definiert die exportierten Funktionen für die DLL-Anwendung.
//

#include "stdafx.h"
#include "Matrix.h"
#include <cmath>
#include <iostream>
using namespace std;


/*
* Class:     Matrix
* Method:    multiplyC
* Signature: ([D[D[DIII)V
*/
JNIEXPORT void JNICALL Java_Matrix_multiplyC(JNIEnv *env, jobject jobj, jdoubleArray a, jdoubleArray b, jdoubleArray r, jint i, jint j, jint k) {
	//Array A
	jboolean isCopyA;
	jdouble* srcArrayAElems =
		env->GetDoubleArrayElements(a, &isCopyA);
	//Array B
	jboolean isCopyB;
	jdouble* srcArrayBElems =
		env->GetDoubleArrayElements(b, &isCopyB);
	//Array R
	jboolean isCopyR;
	jdouble* srcArrayRElems =
		env->GetDoubleArrayElements(r, &isCopyR);
	jint rL = env->GetArrayLength(r);
	//Multiplication
	int ai = 0;
	int bi = 0;
	int hr = 0;
	int br = 0;
	for (int ri = 0; ri < rL; ri++) {
		double res = 0;
		
		if (ri >= (hr + 1)*j) {
			hr++;
			br = 0;
		}

 		for (int x = 0; x < k; x++) {
			ai = k*hr + x;
			bi = br + x*j;
			res = res + srcArrayAElems[ai] * srcArrayBElems[bi];
 		}

		srcArrayRElems[ri] = res;
		
		if (br < j) {
			br++;
		}
	}

	if (isCopyA == JNI_TRUE) {
		env->ReleaseDoubleArrayElements(a, srcArrayAElems, JNI_ABORT);
	}
	if (isCopyB == JNI_TRUE) {
		env->ReleaseDoubleArrayElements(b, srcArrayBElems, JNI_ABORT);
	}
	if (isCopyR == JNI_TRUE) {
		env->ReleaseDoubleArrayElements(r, srcArrayRElems, 0);
	}
}