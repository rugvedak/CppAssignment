//============================================================================
// Name        : 2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int factorial(int);
int main() {
	int number;

	try {
		cout << "Enter number ";
		cin >> number;
		if (number < 0)
			throw number;
		else
			cout << "Factorial of " << number << " = " << factorial(number);
	} catch (int e) {
		cout << "Exception Caught \n";
		cout << "You entered "<<e <<" is negative number" << endl;

	}

	return 0;
}
int factorial(int n) {
	if (n > 1)
		return n * factorial(n - 1);
	else
		return 1;
}
