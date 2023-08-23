/*
 * Stack.h
 *
 *  Created on: 17-Aug-2023
 *      Author: sunbeam
 */

#ifndef STACK_H_
#define STACK_H_
#include <iostream>
#include <vector>
using namespace std;

class Box;

template<typename T>
class Stack {
private:
	vector<T> data;

public:
	void push(const T &item) {
		data.push_back(item);
	}

	void pop() {
		if (!empty()) {
			data.pop_back();
		}
	}

	const T& top() const {
		if (!empty()) {
			return data.back();
		}
		throw runtime_error("Stack is empty.");
	}

	bool empty() const {
		return data.empty();
	}
};

#endif /* STACK_H_ */
