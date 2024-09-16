#include "Fraction.h"
Fraction Fraction::operator+(Fraction b) {
	Fraction c;
	c.setDenominator(this->denominator * b.denominator);
	c.setNumerator(this->numerator * b.denominator + this->denominator * b.numerator);
	c.Reduce();
	return c;
}
Fraction Fraction::operator-(Fraction b) {
	Fraction c;
	c.setDenominator(this->denominator * b.denominator);
	c.setNumerator(this->numerator * b.denominator - this->denominator * b.numerator);
	c.Reduce();
	return c;
}
Fraction Fraction::operator*(Fraction b) {
	Fraction c;
	c.setDenominator(this->denominator * b.denominator);
	c.setNumerator(this->numerator * b.numerator);
	c.Reduce();
	return c;
}
Fraction Fraction::operator/(Fraction b) {
	Fraction c;
	c.setDenominator(this->denominator * b.numerator);
	c.setNumerator(this->numerator * b.denominator);
	c.Reduce();
	return c;
}
Fraction Fraction::operator^(int power) {
	Fraction c;
	if (power == 0) {
	}
	if (power < 0) {
		c.setNumerator(std::pow(this->denominator, power*-1));
		c.setDenominator(std::pow(this->numerator, power*-1));
		c.Reduce();
		return c;
	}
	else {
		c.setNumerator(std::pow(this->numerator, power));
		c.setDenominator(std::pow(this->denominator, power));
		c.Reduce();
		return c;
	}
}
float Fraction::ConvertFraction() {
	return (float(this->numerator) / float(this->denominator));
}

bool Fraction::operator<(Fraction b) {
	return (this->numerator * b.denominator < this->denominator * b.numerator);
}
bool Fraction::operator>(Fraction b) {
	return (this->numerator * b.denominator > this->denominator * b.numerator);
}
bool Fraction::operator==(Fraction b) {
	return (this->numerator * b.denominator == this->denominator * b.numerator);
}
bool Fraction::operator!=(Fraction b) {
	return (this->numerator * b.denominator != this->denominator * b.numerator);
}
int Fraction::gcd() {
	int result = std::min(this->denominator,this->numerator);
	while (result > 0) {
		if (this->numerator % result == 0 && this->denominator % result == 0) {
			break;
		}
		result--;
	}
	return result;
}
void Fraction::Reduce() {
	Fraction c;
	int gcd = this->gcd();
	this->setDenominator(denominator / gcd);
	this->setNumerator(numerator / gcd);
}

void Fraction::OutputFraction() {
	std::cout << '\n' << this->numerator << '/' << this->denominator;
}

Fraction Fraction::InputFraction() {
	Fraction c;
	std::cin >> c.numerator;
	std::cout << "/\n";
	std::cin >> c.denominator;
	if (denominator == 0) {
		std::cerr << "\nERROR: Entered denominator is zero;changing to 1";
		c.denominator = 1;
	}
	return c;
}