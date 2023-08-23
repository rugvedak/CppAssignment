//============================================================================
// Name        : 4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include"../include/Address.h"
using namespace std;

int main() {
	Address address;
	cout<<"Please Enter your Address"<<endl;
	address.accept();
	cout<<"Inputed Address"<<endl;
	address.display();
	return 0;
}
