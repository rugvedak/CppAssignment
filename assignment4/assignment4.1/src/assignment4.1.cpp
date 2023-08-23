//============================================================================
// Name        : 1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
# include "../include/Distance.h"
using namespace std;

int main() {

	Distance d1;
	Distance d2;
	Distance d3;
	int ch, choice;

	do {
		//overloaing the << and >> operator
		cout << "Enter the value of object D1: " << endl;
		cin >> d1;
		cout << "Enter the value of object D2: " << endl;
		cin >> d2;

		cout << "Which Operation do you want to perform?" << endl;
		cout << "1. Overloading  + operator as member function\n2.Overloading == operator as Friend function";
		cout<<"\n3. Overload ++ operator as member function to increment inches";
		cout<<"\n4. Overload -- operator as friend function"<< endl;
		// Use overloaded operator	d3 = d1 + d2;

		cin >> ch;
		switch (ch) {
		case 1:
			d3 = d1 + d2;
			cout << "Addition " << d3 << endl;
			break;
		case 2:
			if (d1 == d2)
				cout << "Equivalent" << endl;
			else
				cout << "Not Equivalent" << endl;
			break;
		case 3:
			cout << "Before increament" << d1 << endl;
			++d1; // d3 = d1.operator++();
			cout << "D1" << d1 << endl;
			break;
		case 4:
			cout << "Before decrement" << d2 << endl;
			--d2; // d3 = d1.operator--();
			cout << "D2" << d2 << endl;
			break;
		}
		cout << "\n enter 1 to continue or 0 to exit  :: ";
		cin >> choice;

	} while (choice != 0);

	return 0;
}
