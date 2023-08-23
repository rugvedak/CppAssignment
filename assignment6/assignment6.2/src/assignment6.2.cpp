//============================================================================
// Name        : 2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "../include/Date.h"
#include "../include/Person.h"
#include "../include/Employee.h"
using namespace std;

int main() {

	Date birthdate;

	cout << "Enter the Person Information" << endl;
	Person p;
	p.accept();
	birthdate.accept();

	cout << "Information about Person" << endl;
	p.display();
	birthdate.print();
	cout<<"\n-------------------------------------"<<endl;

	cout << "Enter the Employee Information" << endl;
	Employee e;
	e.accept();
	birthdate.accept();

	cout << "Information about Employee" << endl;
	e.display();
	birthdate.print();
	cout<<"\n-------------------------------------"<<endl;
	return 0;
}
