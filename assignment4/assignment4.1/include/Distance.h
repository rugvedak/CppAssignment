/*
 * Distance.h
 *
 *  Created on: 04-Aug-2023
 *      Author: sunbeam
 */

#ifndef DISTANCE_H_
#define DISTANCE_H_
# include <iostream>
using namespace std;
class Distance {
public:
	int feet, inches;

	Distance() {
		this->feet = 0;
		this->inches = 0;
	}

	Distance(int f, int i) {
		this->feet = f;
		this->inches = i;
	}

	Distance operator+(const Distance &other) const;
	friend bool operator ==(Distance&, Distance&);
	Distance& operator++(); //pre-increment | as member fn
	friend Distance operator --(Distance&);
	friend ostream& operator<<(ostream&, const Distance&);
	friend istream& operator>>(istream &input, Distance&);

};

#endif /* DISTANCE_H_ */
