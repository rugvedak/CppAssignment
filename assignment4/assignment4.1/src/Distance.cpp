/*
 * Distance.cpp
 *
 *  Created on: 04-Aug-2023
 *      Author: sunbeam
 */
# include "../include/Distance.h"
ostream& operator<<(ostream &output, const Distance &D) {
	output << "F : " << D.feet << " I : " << D.inches;
	return output;
}

istream& operator>>(istream &input, Distance &D) {
	input >> D.feet >> D.inches;
	return input;
}
Distance Distance::operator+(const Distance &other) const {
	Distance res;
	res.feet = this->feet + other.feet;
	res.inches = this->inches + other.inches;
	if (res.inches >= 12) {
		res.inches -= 12;
		res.feet++;
	}
	return res;
}

bool operator ==(Distance &d1, Distance &d2) {
	if (d1.feet == d2.feet && d1.inches == d2.inches)
		return true;
	return false;
}

Distance& Distance::operator++() {
	this->inches++;
	if (this->inches >= 12) {
		this->feet++;
		this->inches = this->inches - 12;
	}
	return *this;
}
Distance operator --(Distance &d1) {
	d1.inches--;
	if (d1.inches >= 12) {
		d1.feet--;
		d1.inches = d1.inches - 12;
	}
	return d1;
}
