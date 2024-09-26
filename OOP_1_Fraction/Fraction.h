#pragma once
#include <iostream>
#include <stdexcept>
#include <cstdlib> //for abs()
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

	Fraction operator+(const Fraction b);
	Fraction operator-(const Fraction b);
	Fraction operator*(const Fraction b);
	Fraction operator/(const Fraction b);
	bool operator<(const Fraction b);
	bool operator>(const Fraction b);
	bool operator==(const Fraction b);
	bool operator!=(const Fraction b);
	void Reduce();
	
	void OutputFraction() const;
	Fraction InputFraction() const;

	Fraction operator^(int power);
	float ConvertFraction() const;

};