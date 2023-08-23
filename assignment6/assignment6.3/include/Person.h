/*
 * Person.h
 *
 *  Created on: 16-Aug-2023
 *      Author: sunbeam
 */

#ifndef PERSON_H_
#define PERSON_H_
#include"../include/Date.h"
class Person {
private:
	char name[40];
	char address[100];
	Date birthdate;
public:
	Person();
	Person(char*,char*,Date);
	const char* getAddress() const;
	const Date& getBirthdate() const;
	void setBirthdate(const Date &birthdate);
	const char* getName() const;
	void accept();
	void display();

};

#endif /* PERSON_H_ */
