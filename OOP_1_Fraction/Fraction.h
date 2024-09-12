#pragma once
class Fraction
{
private:
	int numerator;
	int denominator;
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
};