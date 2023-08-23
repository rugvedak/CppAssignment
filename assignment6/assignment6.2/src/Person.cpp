/*
 * Person.cpp
 *
 *  Created on: 16-Aug-2023
 *      Author: sunbeam
 */

#include "../include/Person.h"
#include "../include/Date.h"
#include <cstring>
#include <iostream>
using namespace std;

Person::Person() {
	// TODO Auto-generated constructor stub

}

const char* Person::getAddress() const {
	return address;
}

const Date& Person::getBirthdate() const {
	return birthdate;
}

void Person::setBirthdate(const Date &birthdate) {
	this->birthdate = birthdate;
}

const char* Person::getName() const {
	return name;
}

Person::Person(char *nm, char *addr, Date bd) {
	strcpy(this->name, nm);
	strcpy(this->address, addr);
	this->birthdate = bd;
}

void Person::accept() {

	cout << "Enter Name: " << endl;
	cin >> this->name;
	cout << "Enter Address: " << endl;
	cin >> this->address;
	cout << "Enter BirthDate: " << endl;
}

void Person::display() {

	cout << "Name: " << this->name << endl;
	cout << "Address: " << this->address << endl;
	cout << "BirthDate: ";


}
