/*
 * Fraction.h
 *
 *  Created on: 09-Aug-2023
 *      Author: sunbeam
 */

#ifndef FRACTION_H_
#define FRACTION_H_

class Fraction {
private:
	int numerator;
	int denominator;

public:
	Fraction();
	Fraction(int n, int d);
	int getDenominator() const;
	void setDenominator(int denominator);
	int getNumerator() const;
	void setNumerator(int numerator);
	void display();

	void lowestForm();
	double decimalValue()const;

	//operator overloading
	Fraction operator+(Fraction otherFrac);
	Fraction operator-(Fraction otherFrac);
	Fraction operator*(Fraction otherFrac);
	Fraction operator/(Fraction otherFrac);
	Fraction operator=(Fraction otherFrac);
	bool operator==(const Fraction&) const;
	bool operator!=(const Fraction&) const;
	bool operator>(const Fraction&) const;
	bool operator<(const Fraction&) const;
};

#endif /* FRACTION_H_ */
