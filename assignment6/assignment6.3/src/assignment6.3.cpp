//============================================================================
// Name        : 3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "../include/Date.h"
#include "../include/Employee.h"
using namespace std;

int main() {
	Date d;
	Employee employee;

	cout<<"Enter Employee Information"<<endl;
	employee.accept();



	employee.display();
	return 0;
}
