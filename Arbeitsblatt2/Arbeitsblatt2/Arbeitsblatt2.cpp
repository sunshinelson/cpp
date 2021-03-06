// Arbeitsblatt2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <memory>
#include <string>
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

	//aus Folien
	int x = 2;
	int y = 9;
	int *px = &x; // px ist die Adresse von x
	int*& rpx = px; // rpx ist ein Alias für px
	*rpx = 4; // x erhält den Wert 4
	rpx = &y; // px erhält die Adresse von y
	px = &x; // px erhält die Adresse von x
	cout << *rpx << endl;

	shared_ptr<string> s;
	{
		auto sp = shared_ptr<string>(new string("shared"));
		cout << *sp << endl;
		cout << "is sp unique? " << boolalpha << sp.unique() << endl;
		s = sp;
		cout << "is sp unique? " << boolalpha << sp.unique() << endl;
		cout << "is s unique? " << boolalpha << s.unique() << endl;
		// Speicher des Strings wird am Ende dieses Blocks NICHT frei gegeben
		// weil s noch auf das String-Objekt zeigt
	}
	cout << "is s unique? " << boolalpha << s.unique() << endl;
	cout << *s << endl;

	shared_ptr<string> t;
	{
		string *p = new string("unique and shared");
		unique_ptr<string> up = unique_ptr<string>(p);
		shared_ptr<string> sp = shared_ptr<string>(p);
		cout << *up << endl; cout << *sp << endl;
		t = sp;
		// Speicher des String-Objekts wird am Ende dieses Blocks frei gegeben,
		// weil der Destruktor von up das String-Objekt vom Heap löscht
		// Referenzzähler von sp wird dekrementiert ( = 1)
	}
	cout << "is t unique? " << boolalpha << t.unique() << endl;
	t = nullptr; // Referenzzähler wird 0, Destruktur führt zu Laufzeitfehler

	return 0;
}

