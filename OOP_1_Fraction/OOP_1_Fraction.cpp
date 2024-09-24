// OOP_1_Fraction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Fraction.h"
#include <iomanip>
using namespace std;

int main()
{
	Fraction a= a.InputFraction();
	cout << setprecision(5) << a.ConvertFraction() << '\n';
	Fraction b= b.InputFraction();
	cout << setprecision(5) << b.ConvertFraction() << '\n';
	cout << "a+b=";
	(a + b).OutputFraction();
	cout << "a-b=";
	(a - b).OutputFraction();
	cout << "a*b=";
	(a * b).OutputFraction();
	cout << "a/b=";
	(a / b).OutputFraction();
	cout << "a>b=" << ((a > b ) ? "True" : "False") << "\n";
	cout << "a>b=" << ((a < b ) ? "True" : "False") << "\n";
	cout << "a==b=" << ((a == b ) ? "True" : "False") << "\n";
	cout << "a!=b=" << ((a != b ) ? "True" : "False") << "\n";

	int pow;
	cout << "Exponent to a: ";
	cin >> pow;
	(a ^ pow).OutputFraction();
	
}
