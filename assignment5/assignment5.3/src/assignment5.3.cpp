//============================================================================
// Name        : 3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "../include/Fraction.h"
using namespace std;
int main() {

	int numerator1, denominator1, numerator2, denominator2;
	cout << "\n Enter 1st Fraction Value ";
	cout << "\n ------------------------- \n";
	cout << "Enter Numerator" << endl;
	cin >> numerator1;
	cout << "Enter denominator" << endl;
	cin >> denominator1;
	Fraction f1(numerator1, denominator1);

	cout << "\n Enter 2nd Fraction Value ";
	cout << "\n ------------------------- \n";
	cout << "Enter Numerator" << endl;
	cin >> numerator2;
	cout << "Enter denominator" << endl;
	cin >> denominator2;
	Fraction f2(numerator2, denominator2);

	Fraction f3;
	cout << "\n -----------------ADDITION--------------------" << endl;
	f3 = f1 + f2;
	f3.display();
	cout << "\n ----------------SUBTRACTION--------------------" << endl;
	f3 = f1 - f2;
	f3.display();
	cout << "\n ---------------MULTIPLICATION--------------------" << endl;
	f3 = f1 * f2;
	f3.display();
	cout << "\n ------------------DIVISION--------------------" << endl;
	f3 = f1 / f2;
	f3.display();

	cout << "\n -----------------EQUALITY--------------------" << endl;
	cout << "f1 == f2:" << (f1 == f2) << endl;
	cout << "\n ---------------NOT EQUALITIY------------------" << endl;
	cout << "f1!=f2: " << (f1 != f2) << endl;
	cout << "\n ---------------COMPARISION----------------------" << endl;
	cout << "f1<f2: " << (f1 < f2) << endl;
	cout << "\n ---------------COMPARISION------------------" << endl;
	cout << "f1>f2: " << (f1 > f2) << endl;
	cout << "\n -------------------------------------" << endl;
	return 0;
}
