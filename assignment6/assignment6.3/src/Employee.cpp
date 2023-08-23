/*
 * Employee.cpp
 *
 *  Created on: 16-Aug-2023
 *      Author: sunbeam
 */
#include<iostream>
#include <cstring>
#include "../include/Employee.h"
#include "../include/Date.h"
using namespace std;
Date jd;
Employee::Employee() {
	// TODO Auto-generated constructor stub

}
Employee::Employee(char* name,char* address,Date birthDate,int id ,float sal,char* dept,Date joinDate) {

	::Person(name,address,birthDate);
	this->id = id;
	this->sal = sal;
	strcpy(this->dept,dept);
	this->joiningDate=joinDate;
}

const char* Employee::getDept() const {
	return dept;
}

int Employee::getId() const {
	return id;
}

void Employee::setId(int id) {
	this->id = id;
}

const Date& Employee::getJoiningDate() const {
	return joiningDate;
}

void Employee::setJoiningDate(const Date &joiningDate) {
	this->joiningDate = joiningDate;
}

float Employee::getSal() const {
	return sal;
}

void Employee::setSal(float sal) {
	this->sal = sal;
}
void Employee::accept()
{
	Person::accept();
	cout<<"Enter ID: "<<endl;
	cin>>this->id;
	cout<<"Enter Salary: "<<endl;
	cin>>this->sal;
	cout<<"Enter Department: "<<endl;
	cin>>this->dept;
	cout<<"Enter Joining Date: "<<endl;
	jd.accept();
}
void Employee::display()
{
	Person::display();
	cout<<"ID: "<<this->id<<endl;
	cout<<"Salary: "<<this->sal<<endl;
	cout<<"Department: "<<this->dept<<endl;
	cout<<"Joining Date: ";
	jd.print();
}
