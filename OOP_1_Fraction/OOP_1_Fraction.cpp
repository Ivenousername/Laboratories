// OOP_1_Fraction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Fraction.h"
#include <iomanip>
using namespace std;

int main()
{
	Fraction a;
	a.Input();
	cout << setprecision(5) << a.ToFloat() << '\n';
	Fraction b;
	b.Input();
	cout << setprecision(5) << b.ToFloat() << '\n';
	cout << "a+b=";
	(a + b).Output();
	cout << "a-b=";
	(a - b).Output();
	cout << "a*b=";
	(a * b).Output();
	cout << "a/b=";
	(a / b).Output();
	cout << "a>b=" << ((a > b ) ? "True" : "False") << "\n";
	cout << "a>b=" << ((a < b ) ? "True" : "False") << "\n";
	cout << "a==b=" << ((a == b ) ? "True" : "False") << "\n";
	cout << "a!=b=" << ((a != b ) ? "True" : "False") << "\n";

	int pow;
	cout << "Exponent to a: ";
	cin >> pow;
	(a ^ pow).Output();
	
}
