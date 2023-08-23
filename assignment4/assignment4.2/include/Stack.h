/*
 * Stack.h
 *
 *  Created on: 05-Aug-2023
 *      Author: sunbeam
 */

#ifndef STACK_H_
#define STACK_H_

//predefine macro with size 5

// creating class to implementing the stack
class Stack {
private:
	int *arr;
	int size;
	int top;
public:
	//constructor
	Stack();
	//parameterized ctor
	Stack(int);
	//copy ctor
	Stack(const Stack&);

	//assignment operator overloading
	Stack& operator =(const Stack&);

	bool isFull();
	bool isEmpty();
	int peek();

	void pop();
	void push(int);

	void PrintStack();
	virtual ~Stack();

};

#endif /* STACK_H_ */
