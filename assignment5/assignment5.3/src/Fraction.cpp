/*
 * Fraction.cpp
 *
 *  Created on: 09-Aug-2023
 *      Author: sunbeam
 */
#include<iostream>
#include "../include/Fraction.h"
using namespace std;

int gcd(int m, int n) {
	/** gcd is a helper function, used by but not part of the Fraction class */
	while (m % n != 0) {
		int oldm = m;
		int oldn = n;

		m = oldn;
		n = oldm % oldn;
	}
	return n;
}
Fraction::Fraction() {
	this->numerator = 0;
	this->denominator = 1;
	lowestForm();
}

Fraction::Fraction(int n, int d) {
	this->numerator = n;
	this->denominator = d;
}
inline int Fraction::getDenominator() const {
	return denominator;
}

inline void Fraction::setDenominator(int denominator) {
	if (denominator == 0)
		throw "he denominator is zero.";
	this->denominator = denominator;
}

inline int Fraction::getNumerator() const {
	return numerator;
}

inline void Fraction::setNumerator(int numerator) {
	this->numerator = numerator;
}

void Fraction::lowestForm() {
	int common = gcd(numerator, denominator);
	numerator /= common;
	denominator /= common;
}
double Fraction::decimalValue() const {
	return static_cast<double>(numerator) / denominator;
}
void Fraction::display() {

	cout << this->numerator << "/" << this->denominator << endl;
}

Fraction Fraction::operator+(Fraction otherFrac) {
	int newnum = this->numerator * otherFrac.denominator
			+ this->denominator * otherFrac.numerator;
	int newden = this->denominator * otherFrac.denominator;
	int common = gcd(newnum, newden);
	return Fraction(newnum / common, newden / common);
}

Fraction Fraction::operator-(Fraction otherFrac) {
	int newnum = this->numerator * otherFrac.denominator
			- this->denominator * otherFrac.numerator;
	int newden = this->denominator * otherFrac.denominator;
	int common = gcd(newnum, newden);
	return Fraction(newnum / common, newden / common);
}

Fraction Fraction::operator*(Fraction otherFrac) {
	int newnum = this->numerator * otherFrac.numerator;
	int newden = this->denominator * otherFrac.denominator;
	int common = gcd(newnum, newden);
	return Fraction(newnum / common, newden / common);
}
Fraction Fraction::operator/(Fraction otherFrac) {
	int newnum = this->numerator * otherFrac.denominator;
	int newden = this->denominator * otherFrac.numerator;
	int common = gcd(newnum, newden);
	return Fraction(newnum / common, newden / common);
}
Fraction Fraction::operator=(Fraction otherFrac) {
	this->numerator = otherFrac.numerator;
	this->denominator = otherFrac.denominator;
	return *this;
}

bool Fraction::operator==(const Fraction &f) const {
	return numerator * f.denominator == denominator * f.numerator;
}

bool Fraction::operator!=(const Fraction &f) const {
	return !(*this == f);
}
bool Fraction::operator>(const Fraction &f) const {
	return (float) numerator / denominator > (float) f.numerator / f.denominator;
}
bool Fraction::operator<(const Fraction &f) const {
	return f > *this;
}
