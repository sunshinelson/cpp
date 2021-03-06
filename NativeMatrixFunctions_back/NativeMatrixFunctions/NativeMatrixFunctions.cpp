// NativeMatrixFunctions.cpp: Definiert die exportierten Funktionen für die DLL-Anwendung.
//

#include "stdafx.h"
#include "Matrix.h"

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
	int step = k;
	for (int ri = 0; ri < rL; ri++) {
			double res = 0;
			for (int x = (step - k); x < step; x++) {
				res = res + srcArrayAElems[ai] * srcArrayBElems[bi];
				ai++;
				bi = bi + j;
			}
			ai = step;
			bi = 0;
			step = step + k;
			srcArrayRElems[ri] = res;
	}
}

