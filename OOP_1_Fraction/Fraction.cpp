#include "Fraction.h"
Fraction Fraction::operator+(Fraction b) {
	Fraction c;
	if (this->denominator == b.denominator) {
		c.setDenominator(b.denominator);
		c.setNumerator(this->numerator + b.numerator);
		return c;
	}
	else {
		c.setDenominator(this->denominator * b.denominator);
		c.setNumerator(this->numerator * b.denominator + this->denominator * b.numerator);
		return c;
	}
}
Fraction Fraction::operator-(Fraction b) {
	Fraction c;
	if (this->denominator == b.denominator) {
		c.setDenominator(b.denominator);
		c.setNumerator(this->numerator - b.numerator);
		return c;
	}
	else {
		c.setDenominator(this->denominator * b.denominator);
		c.setNumerator(this->numerator * b.denominator - this->denominator * b.numerator);
		return c;
	}
}
Fraction Fraction::operator*(Fraction b) {
	Fraction c;
	c.setDenominator(this->denominator * b.denominator);
	c.setNumerator(this->numerator * b.numerator);
	return c;
}
Fraction Fraction::operator/(Fraction b) {
	Fraction c;
	c.setDenominator(this->denominator * b.numerator);
	c.setNumerator(this->numerator * b.denominator);
	return c;
}