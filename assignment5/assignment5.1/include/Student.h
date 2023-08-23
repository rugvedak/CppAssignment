/*
 * Student.h
 *
 *  Created on: 04-Aug-2023
 *      Author: sunbeam
 *
 */

#ifndef STUDENT_H_
#define STUDENT_H_

class Student {
private:
	char name[50];
	char gender[10];
	int rollNumber, m1, m2, m3;
	double percentage;
public:
	Student();
	void acceptStudent();
	void printStudent();
	double percent();

	const char* getGender() const;

	int getM1() const;

	void setM1(int m1);

	int getM2() const;

	void setM2(int m2);

	int getM3() const;

	void setM3(int m3);
	const char* getName() const;

	double getPercentage() const;

	void setPercentage(double percentage);

	int getRollNumber() const;
	void setRollNumber(int rollNumber);
};

#endif /* STUDENT_H_ */
