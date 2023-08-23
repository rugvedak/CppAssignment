/*
 * Stack.cpp
 *
 *  Created on: 05-Aug-2023
 *      Author: sunbeam
 */
#include"../include/Stack.h"
#include <iostream>
using namespace std;
Stack::Stack(){
	top = -1;
	size=0;
}
Stack::Stack(int size) {
	this->top = -1;
	this->size=size;
	if (size <= 0) {
		throw invalid_argument("Stack size must be positive.");
	}
	arr = new int(size);
}
Stack::Stack(const Stack& other) {
	this->top=other.top;
	this->size = other.size;
	arr = new int(size);
	for (int i = 0; i < size; i++) {
		arr[i] = other.arr[i];
	}
}

Stack& Stack::operator=(const Stack& other) {
       if (this != &other) { // Self-assignment check
    	   delete [ ] arr;
           size = other.size;
           top=other.top;
           arr = new int(size);
            for (int i = 0; i < size; ++i) {
               this->arr[i] = other.arr[i];
           }
       }
       return *this;
   }

bool Stack::isFull() {
	return this->top == (size - 1);
}
bool Stack::isEmpty() {
	return this->top == -1;
}
int Stack::peek() {
	int value;
	if (this->isEmpty())
		cout << "Stack is Empty" << endl;
	else {
		value = this->arr[this->top];
	}
	return value;
}
void Stack::pop() {
	if (this->isEmpty())
		cout << "stack is empty" << endl;
	else {
		this->arr[this->top] = -1;
		this->top--; //this->top=this->top-1;
	}
}
void Stack::push( int value) {
	if (this->isFull())
		cout << "stack is full" << endl;
	else {
		this->top++; //this->top= this->top+1;
		this->arr[this->top] = value;

	}

}
void Stack::PrintStack() {
	for (int i = 0; i < size; i++) {
		cout << "[ " << arr[i] << " ]" << "\t";
	}
	cout << "top=" << this->top << endl;
}

Stack::~Stack() {
	delete[] arr;
}

