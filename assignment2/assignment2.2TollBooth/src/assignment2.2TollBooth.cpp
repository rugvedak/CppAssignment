//============================================================================
// Name        : 2TollBooth.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include<iostream>
using namespace std;
class TollBooth {
private:
	unsigned int car;
	double money;
public:
	TollBooth() :
			car(0), money(0) {
	}
	void payingCar() {
		car += 1;
		money += 0.5;
	}
	void nopayCar() {
		car = car + 1;
	}
	void display() {
		cout << "\n\ninformation about the tollbooth\n\n";
		cout << "\tTollamount\tNoof passing cars\n\n";
		cout << "\t" << money << "\t\t\t" << car;
	}
};

int main() {
	char ch='y', x;
	TollBooth d;
	while (ch == 'y') {
		cout << "Enter 1 For Toll Paying Cars \n 2 For Non-Toll Paying Cars = ";
		cout << "3.for display the collected information:";
		cout << "";
		cin >> x;
		switch (x) {
		case '1':
			d.payingCar();
			break;
		case '2':
			d.nopayCar();
			break;
		case '3':
			d.display();
			break;
		}

		cout << "Want to perform more oprations(y/n)?";
		cin >> ch;
	}
}
