/*
 * Box.h
 *
 *  Created on: 17-Aug-2023
 *      Author: sunbeam
 */

#ifndef BOX_H_
#define BOX_H_
#include <iostream>
using namespace std;

// Hypothetical Box class
class Box {
private:
	int width;
	int height;

public:
	Box(int w, int h) :
			width(w), height(h) {
	}

	friend std::ostream& operator<<(std::ostream &os, const Box &box) {
		os << "Box(" << box.width << "x" << box.height << ")";
		return os;
	}
};

#endif /* BOX_H_ */
