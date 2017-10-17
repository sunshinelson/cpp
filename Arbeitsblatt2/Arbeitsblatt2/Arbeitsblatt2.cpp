// Arbeitsblatt2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <cmath>

//A3 Pointer
void swapPointer(int* p, int* q) {
	int temp =*p;
	*p = *q;
	*q = temp;
}

//A3 Reference
void swapReference(int& a, int& b) {
	int c = a;
	a = b;
	b = c;
}

//A4
int* mySmartFunc() {
	int ghostInTheMachine = 42;
	return &ghostInTheMachine;
}

//A5
void sinus(int a, double b) {
	double bb = b / 6.28;
	for (int i = a; i >= -a; i--) {
		for (int j = 0; j < b; j++) {
			cout << ((int)round(a*sin(j / bb)) == i ? '*' : ' ');
		}
		cout << endl;
	}
}

int main()
{
	int a = 3;
	int b = 6;

	cout << "a: " << a << " b: " << b << endl;
	swapPointer(&a, &b);
	cout << "a swap: " << a << " b swap: " << b << endl;

	int c = 3, d = 6;
	cout << "c: " << c << " d: " << d << endl;
	swapReference(c, d);
	cout << "c swap: " << c << " d swap: " << d << endl;
	
	cout << *mySmartFunc() << endl;
	sinus(14, 60);
	return 0;
}

