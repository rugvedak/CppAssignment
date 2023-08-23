/*
 * Employee.h
 *
 *  Created on: 16-Aug-2023
 *      Author: sunbeam
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include "../include/Date.h"
#include "../include/Person.h"
class Employee :public Person {
private:
	int id;
	float sal;
	char dept[40];
	Date joiningDate;
public:
	Employee();
	Employee(char*,char*,Date,int,float,char*,Date);
	const char* getDept() const;
	int getId() const;
	void setId(int id);
	const Date& getJoiningDate() const;
	void setJoiningDate(const Date &joiningDate);
	float getSal() const;
	void setSal(float sal);
	void accept();
	void display();
};

#endif /* EMPLOYEE_H_ */
