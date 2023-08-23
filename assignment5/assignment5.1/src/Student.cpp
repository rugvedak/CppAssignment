/*
 * Student.cpp
 *
 *  Created on: 04-Aug-2023
 *      Author: sunbeam
 */
#include <iostream>
#include<stdio.h>
#include "../include/Student.h"
using namespace std;
Student::Student(){

}
void Student::acceptStudent() {
	cout << "Roll Number: " << endl;
	cin >> this->rollNumber;
	cout << "Name: " << endl;
	cin >> this->name;
	cout << "Gender: (female/male)" << endl;
	cin >> this->gender;
	cout << "Marks of 3 subject" << endl;
	cin >> this->m1 >> this->m2 >> this->m3;
}
double Student::percent() {
	double addition = this->m1 + this->m2 + this->m3;
	double percent = ((addition / 300) * 100);
	return percent;
}
void Student::printStudent() {
	cout << "Roll Number: " << this->rollNumber << endl;
	cout << "Name: " << this->name << endl;
	cout << "Gender: " << this->gender << endl;
	cout << "Percentage: " << this->percent() << endl;
	cout << "------------------" << endl;
}

const char* Student::getGender() const {
	return gender;
}

int Student::getM1() const {
	return m1;
}

void Student::setM1(int m1) {
	this->m1 = m1;
}

int Student::getM2() const {
	return m2;
}

void Student::setM2(int m2) {
	this->m2 = m2;
}

int Student::getM3() const {
	return m3;
}

void Student::setM3(int m3) {
	this->m3 = m3;
}

const char* Student::getName() const {
	return name;
}

double Student::getPercentage() const {
	return percentage;
}

void Student::setPercentage(double percentage) {
	this->percentage = percentage;
}

int Student::getRollNumber() const {
	return rollNumber;
}

void Student::setRollNumber(int rollNumber) {
	this->rollNumber = rollNumber;
}
