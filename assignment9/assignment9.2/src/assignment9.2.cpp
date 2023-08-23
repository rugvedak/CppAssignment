//============================================================================
// Name        : 2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "../include/Stack.h"
#include "../include/Box.h"
using namespace std;

int main() {

	Stack<int> intStack;
	int size, intdata;
	cout << "Enter how many element do you want?";
	cin >> size;
	cout << "Enter data" << endl;
	for (int var = 0; var < size; var++) {
		cin >> intdata;
		intStack.push(intdata);
	}

	cout << "Top of intStack: " << intStack.top() << endl;
	intStack.pop();
	cout << "Top of intStack after pop: " << intStack.top() << endl;

	cout << "----------------------------------------" << endl;

	// Testing Stack<double>
	Stack<double> doubleStack;
	double doubledata;
	cout << "Enter data" << endl;
		for (int var = 0; var < size; var++) {
			cin >> doubledata;
			doubleStack.push(doubledata);
		}

	std::cout << "Top of doubleStack: " << doubleStack.top() << std::endl;
	doubleStack.pop();
	std::cout << "Top of doubleStack after pop: " << doubleStack.top()
			<< std::endl;

	// Testing Stack<Box>
	Stack<Box> boxStack;


	Box box1(5, 5);
	Box box2(10, 10);
	boxStack.push(box1);
	boxStack.push(box2);
	std::cout << "Top of boxStack: " << boxStack.top() << std::endl;
	boxStack.pop();
	std::cout << "Top of boxStack after pop: " << boxStack.top() << std::endl;

	return 0;
}
