// Expression.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Expression.h"
#include "Vector.h"
#include <iostream>
using namespace std;


int main()
{
	Vector<double, 4> A({ 1.0, 2.0, 3.0, 4.0 });
	Vector<double, 4> B({ 2.0, 1.0, 0.0, 1.0 });
	Vector<double, 4> D;
	auto e = (A - B) * (A + B);
	cout << e << endl;
	//auto e = (A + B);
	D = e;
	cout << D << endl; // [-3,3,9,15]
	B = { 3.0, 0.0, 2.0, 5.0 };
	cout << e << endl; // [-8,4,5,-9]
	B = { 4.0, 3.0, 3.0, -2.0 };
	cout << e[1] << endl; // -5
	bool b = A == B;
	cout << b << endl;
	cout << "------------------------------" << endl;
	Vector<double, 5> X({ 1, 2, 3, 4, 5 });
	Vector<double, 5> Y({ 1, 4, 9, 16, 25 });
	Vector<double, 5> Z;
	Z = X*X;
	cout << Z << endl;
	auto f = (2.0*(A - B) / 2.0 + B + 5.0) * (A - 4.0 + 4.0*B) / 4.0;
	//auto f = 2.0*(A - B);
	cout << f << endl;
	return 0;
}

