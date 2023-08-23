/*
 * Address.cpp
 *
 *  Created on: 05-Aug-2023
 *      Author: sunbeam
 */
#include<iostream>
#include<cstring>
#include "../include/Address.h"
using namespace std;
Address::Address() {
	strcpy(this->building, "");
	strcpy(this->street, "");
	strcpy(this->city, "");
	this->pin = 0;
}
Address::Address(char *building, char *street, char *city, int pin) {
	strcpy(this->building, building);
	strcpy(this->street, street);
	strcpy(this->city, city);
	this->pin = pin;

}
inline const char* Address::getBuilding() const {

	return building;
}

inline const char* Address::getCity() const {
	return city;
}

inline int Address::getPin() const {
	return pin;
}

void Address::setBuilding(char *building) {
	strcpy(this->building, building);
}

void Address::setCity(char *city) {
	strcpy(this->city, city);
}

void Address::setStreet(char *street) {
	strcpy(this->street, street);
}

inline void Address::setPin(int pin) {
	this->pin = pin;
}

void Address::accept() {
	cout << "Enter Pin" << endl;
	cin >> this->pin;
	cout << "Enter Building Name: " << endl;
	cin.getline(this->building, 30, '#');
	cout << "Enter Street: " << endl;
	cin.getline(this->street, 30, '#');
	cout << "Enter City: " << endl;
	cin.getline(city,20,'#');
}
void Address::display() {
	cout << "Address: ";
	cout << this->building << "," << this->street << "," << this->city << ","
			<< this->pin;

}
