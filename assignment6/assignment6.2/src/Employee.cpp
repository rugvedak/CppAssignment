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

Employee::Employee() {
	// TODO Auto-generated constructor stub

}
Employee::Employee(int id, float sal, char* dept, Date joinDate) {

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
	cout<<"Enter ID: "<<endl;
	cin>>this->id;
	cout<<"Enter Salary: "<<endl;
	cin>>this->sal;
	cout<<"Enter Department: "<<endl;
	cin>>this->dept;
	cout<<"Enter Joining Date: "<<endl;
}
void Employee::display()
{
	cout<<"ID: "<<this->id<<endl;
	cout<<"Salary: "<<this->sal<<endl;
	cout<<"Department: "<<this->dept<<endl;
	cout<<"Joining Date: ";
}
