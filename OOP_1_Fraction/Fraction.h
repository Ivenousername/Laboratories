#pragma once
#include <iostream>
#include <stdexcept>
#include <cstdlib> //for abs()
class Fraction
{
public:
	Fraction(int numerator = 1, int denominator = 1);
	int getNumerator() const;
	int getDenominator() const;
	void SetNumerator(const int numerator);
	void SetDenominator(const int denominator);
	Fraction operator+(const Fraction b) const;
	Fraction operator-(const Fraction b) const;
	Fraction operator*(const Fraction b) const;
	Fraction operator/(const Fraction b) const;
	bool operator<(const Fraction b) const;
	bool operator>(const Fraction b) const;
	bool operator==(const Fraction b) const;
	bool operator!=(const Fraction b) const;
	void Reduce();
	
	void Output() const;
	void Input();

	Fraction operator^(const int power) const;
	float ToFloat() const;

private:
	int numerator;
	int denominator;
	int gcd() const;
};