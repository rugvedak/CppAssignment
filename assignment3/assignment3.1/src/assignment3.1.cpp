//============================================================================
// Name        : 1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class Cylinder {
private:
	double radius, height;
public:
	Cylinder():radius(0),height(0) {
		cout<<"Constructor initialized"<<endl;
	}
	Cylinder(double radius, double height):radius(radius), height(height){
		cout<<"Parameterized intialized"<<endl;
	}

	double getHeight() const {
		return height;
	}

	void setHeight(double height) {
		this->height = height;
	}

	double getRadius() const {
		return radius;
	}

	void setRadius(double radius) {
		this->radius = radius;
	}
	double getVolume() {
		return (3.14*this->radius*this->height);
	}
	void printVolume() {
		cout<<"Radius: "<<getRadius()<<endl;
		cout<<"Height: "<<getHeight()<<endl;
		cout<<"Volume of Cylinder:"<<getVolume()<<endl;
	}
};
int main() {

	double radius,height;
	cout<<"Enter Radius of Cylinder: "<<endl;
	cin>>radius;
	cout<<"Enter Height of Cylinder: "<<endl;
	cin>>height;
	Cylinder cylinder(radius,height);
	cylinder.printVolume();
}
