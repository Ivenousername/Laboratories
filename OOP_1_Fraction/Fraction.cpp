#include "Fraction.h"
Fraction Fraction::operator+(Fraction b) {
	Fraction c;
	c.setNumerator(this->getNumerator() * b.getDenominator() + this->getDenominator() * b.getNumerator());
	c.setDenominator(this->getDenominator() * b.getDenominator());
	return c;
}