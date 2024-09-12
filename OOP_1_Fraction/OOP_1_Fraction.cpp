// OOP_1_Fraction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Fraction.h"

int main()
{
	Fraction a(4, 7);
	Fraction b(2, 5);
	Fraction c = a/b;
	std::cout << c.getNumerator() << '/' << c.getDenominator();
}
