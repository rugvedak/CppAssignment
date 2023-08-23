//============================================================================
// Name        : 3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
namespace NStudent {
class Student {
private:
	int rollno, marks;
	char name[50];
public:
	void initStudent(Student *ptrStudent);
	void printStudentOnConsole(Student *ptrStudent);
	void acceptStudentFromConsole(Student *ptrStudent);
	int MenuChoice();
};
void Student::initStudent(Student *ptrStudent) {
	ptrStudent->rollno = 1;
	strcpy(ptrStudent->name, "");
	ptrStudent->marks = 0;
}
void Student::printStudentOnConsole(Student *ptrStudent) {
	cout << "Roll No.: " << ptrStudent->rollno << endl;
	cout << "Name: " << ptrStudent->name << endl;
	cout << "Marks: " << ptrStudent->marks << endl;
}
void Student::acceptStudentFromConsole(Student *ptrStudent) {
	cout << "Roll No.: " << endl;
	cin >> ptrStudent->rollno;
	cout << "Name: " << endl;
	cin >> ptrStudent->name;
	cout << "Marks: " << endl;
	cin >> ptrStudent->marks;
}
int Student::MenuChoice() {
	int choice;
	cout << "1. Accept Student Record " << endl;
	cout << "2. Print Student Record" << endl;
	cout << "0.Exit" << endl;
	printf("\n Enter Your choice :: ");
	scanf("%d", &choice);
	return choice;
}
}
using namespace NStudent;
int main() {
	Student student;
	int choice;
	do {
		choice = student.MenuChoice();

		switch (choice) {
		case 1:
			//accept record
			student.acceptStudentFromConsole(&student);
			break;
		case 2:
			// read  data
			student.printStudentOnConsole(&student);
			break;
		default:
			cout << "Invalid choice !!";
			continue;
		}

		printf("\n enter 1 to continue or 0 to exit  :: ");
		scanf("%d", &choice);

	} while (choice != 0);
	return 0;
}
