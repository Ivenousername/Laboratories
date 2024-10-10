#include "Fraction.h"

Fraction::Fraction(int numerator, int denominator) {
	SetNumerator(numerator);
	SetDenominator(denominator);
}
int Fraction::getNumerator() const {
	return this->numerator;
}
int Fraction::getDenominator() const {
	return this->denominator;
}
void Fraction::SetNumerator(const int numerator) {
	this->numerator = numerator;
}
void Fraction::SetDenominator(const int denominator) {
	this->denominator = denominator;
}
Fraction Fraction::operator+(const Fraction b) const {
	Fraction c;
	c.SetDenominator(this->denominator * b.denominator);
	c.SetNumerator(this->numerator * b.denominator + this->denominator * b.numerator);
	c.Reduce();
	return c;
}
Fraction Fraction::operator-(const Fraction b) const {
	Fraction c;
	c.SetDenominator(this->denominator * b.denominator);
	c.SetNumerator(this->numerator * b.denominator - this->denominator * b.numerator);
	c.Reduce();
	return c;
}
Fraction Fraction::operator*(const Fraction b) const {
	Fraction c;
	c.SetDenominator(this->denominator * b.denominator);
	c.SetNumerator(this->numerator * b.numerator);
	c.Reduce();
	return c;
}
Fraction Fraction::operator/(const Fraction b) const {
	Fraction c;
	c.SetDenominator(this->denominator * b.numerator);
	c.SetNumerator(this->numerator * b.denominator);
	c.Reduce();
	return c;
}
Fraction Fraction::operator^(const int power) const { //Unique function number 1
	Fraction c;
	if (power == 0) {
		return c;
	}
	if (power < 0) {
		c.SetNumerator(std::pow(this->denominator, power*-1));
		c.SetDenominator(std::pow(this->numerator, power*-1));
		c.Reduce();
		return c;
	}
	else {
		c.SetNumerator(std::pow(this->numerator, power));
		c.SetDenominator(std::pow(this->denominator, power));
		c.Reduce();
		return c;
	}
}
float Fraction::ToFloat() const { //Unique function number 2
	return (float(this->numerator) / float(this->denominator));
}

bool Fraction::operator<(const Fraction b) const {
	return (this->numerator * b.denominator < this->denominator * b.numerator);
}
bool Fraction::operator>(const Fraction b) const {
	return (this->numerator * b.denominator > this->denominator * b.numerator);
}
bool Fraction::operator==(const Fraction b) const {
	return (this->numerator * b.denominator == this->denominator * b.numerator);
}
bool Fraction::operator!=(const Fraction b) const {
	return (this->numerator * b.denominator != this->denominator * b.numerator);
}
int Fraction::gcd() const{ //greatest common divisor
	int result = std::min(abs(this->denominator),abs(this->numerator)); //abs from cstdlib 
	while (result > 0) {
		if (this->numerator % result == 0 && this->denominator % result == 0) {
			break;
		}
		result--;
	}
	return result;
}
void Fraction::Reduce() {
	if (numerator == 0) { //If the numerator is 0 the reduction is pointless 
		denominator = 0;
		return;
	}
	if (denominator == 0) {
		std::cerr << "\nERROR: denominator is 0;changing to 1\n";
		denominator = 1;
	}
	Fraction c;
	int gcd = this->gcd();
	this->SetDenominator(denominator / gcd);
	this->SetNumerator(numerator / gcd);
	if (this->getDenominator() < 0) {
		denominator = denominator*-1;
		numerator = numerator*-1;
	}
}

void Fraction::Output() const {
	std::cout << this->numerator << '/' << this->denominator << "\n";
}

void Fraction::Input() {
	std::cin >> this->numerator;
	std::cout << "/\n";
	std::cin >> this->denominator;
	if (denominator == 0) {
		std::cerr << "\nERROR: Entered denominator is zero;changing to 1\n";
		this->denominator = 1;
	}
}