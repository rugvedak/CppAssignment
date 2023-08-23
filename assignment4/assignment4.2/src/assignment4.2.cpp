//============================================================================
// Name        : 3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "../include/Stack.h"
// to use fixed constant values
typedef enum menuchoice {
	Exit = 0, Push_Element, Pop_Element, Peek_Element, Print_Stack
} MENUCHOCIE;

int MenuChoice();
void AcceptRecord(int &data);
void PrintRecord(int &data);

int main() {

	int data, size; // to add data  as integer number

	//Stack original stack
	cout << "Enter how many size" << endl;
	cin >> size;
	Stack originalstack(size); // creating class object parameterized ctor

	for (int i = 0; i < size; i++) {
		AcceptRecord(data);
		originalstack.push(data);
	}

	cout << "----Before copying data in original stack" << endl;
	originalstack.PrintStack();

	cout << "Use of copy ctor" << endl;
	Stack copyStack(originalstack);
	cout << "After copying stack will be" << endl;
	copyStack.PrintStack();


	cout<<"Use of assignment operator"<<endl;
	Stack assignedStack(size);
	assignedStack = originalstack;
	assignedStack.PrintStack();
	cout << "--------------------------------------------" << endl;

	int choice,size2;

	cout << "Enter how many size" << endl;
	cin >> size2;

	Stack stack(size2);

	do {

		choice = MenuChoice();
		switch (choice) {
		case Push_Element: // Push
			if (!stack.isFull()) { //checking the condition here is stack is not full
				AcceptRecord(data);
				stack.push(data);
				stack.PrintStack();
			} else
				cout << "stack is full" << endl;
			break;
		case Pop_Element: // Pop
			if (!stack.isEmpty()) {
				data = stack.peek();
				stack.pop();
				cout << "poped value =" << data << endl;
				stack.PrintStack();
			} else {
				cout << "stack is empty" << endl;
			}

			break;
		case Peek_Element: // Peek
			if (!stack.isEmpty()) {
				data = stack.peek();
				cout << "poped value =" << data << endl;
				stack.PrintStack();
			} else
				cout << "Stack is empty" << endl;
			break;
		case Print_Stack: // print stack

			stack.PrintStack();
			break;
		default:
			cout << "invalid choice" << endl;
			continue;

		}

		cout << "Enter 1 to continue or 0 to Exit";
		cin >> choice;

	} while (choice != 0);

	return 0;
}
void AcceptRecord(int &data) {
	cout << "Enter value :: ";
	cin >> data;
}
void PrintRecord(int &data) {
	cout << "data :: " << data << endl;
}

int MenuChoice() {
	int choice;
	cout << "1. Push (add element into stack )" << endl;
	cout << "2. Pop (remove element from stack )" << endl;
	cout << "3. Peek (display top element from stack )" << endl;
	cout << "4. Print Stack " << endl;

	cout << "Enter Your Choice :: ";
	cin >> choice;
	return choice;
}
