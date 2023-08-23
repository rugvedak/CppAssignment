/*
 * Address.h
 *
 *  Created on: 05-Aug-2023
 *      Author: sunbeam
 */

#ifndef ADDRESS_H_
#define ADDRESS_H_

#include<iostream>
#include <string>
class Address {
private:
	int pin;
	char city[20];
	char street[30];
	char building[30];
public:
	Address();
	Address(char*, char*, char*, int);
	void accept();
	void display();
	const char* getBuilding() const;
	const char* getCity() const;
	int getPin() const;
	void setPin(int pin);
	const char* getStreet() const;
	void setBuilding(char *building);
	void setCity(char *city);
	void setStreet(char *street);
};

#endif /* ADDRESS_H_ */
