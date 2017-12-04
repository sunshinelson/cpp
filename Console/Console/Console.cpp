// Console.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "../../MySet/MySet/MySet.h"
using namespace std;


int main()
{
	//Set s1;
	//Set s11(s1);
	//const int set2[] = { 1,2,3 };
	//Set s2(sizeof(set2) / sizeof(int), set2);
	//Set s21(s2);
	//Set s22 = s2;

	cout << "Move Semantik:" << endl;

	const int set3[] = { 1,2,3 };
	const int set4[] = { 2,3,4 };
	Set s = Set::difference(Set(sizeof(set3) / sizeof(int), set3), Set( sizeof(set4) / sizeof(int), set4));
	cout << s << endl;

	return 0;
}

