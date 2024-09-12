#pragma once
#include <iostream>
class Fraction
{
private:
	int numerator;
	int denominator;
	int gcd();

public:
	Fraction(int numerator=1, int denominator=1) {
		setNumerator(numerator);
		setDenominator(denominator);
	}
	int getNumerator() {
		return this->numerator;
	}
	int getDenominator() {
		return this->denominator;
	}
	void setNumerator(int numerator) {
		this->numerator = numerator;
	}
	void setDenominator(int denominator) {
		this->denominator = denominator;
	}

	Fraction operator+(Fraction b);
	Fraction operator-(Fraction b);
	Fraction operator*(Fraction b);
	Fraction operator/(Fraction b);
	bool operator<(Fraction b);
	bool operator>(Fraction b);
	bool operator==(Fraction b);
	bool operator!=(Fraction b);
	void Reduce();
	
	void OutputFraction();
	Fraction InputFraction();

	Fraction operator^(int power);
	float ConvertFraction();
};