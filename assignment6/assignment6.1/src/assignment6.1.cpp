//============================================================================
// Name        : 1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "../include/Account.h"
using namespace std;
#define SIZE 2
int MenuChoice() {
	int choice;
	printf("\n 1. Deposit ");
	printf("\n 2. Withdraw");
	printf("\n Enter Your choice :: ");
	scanf("%d", &choice);
	return choice;
}

int main() {

	Account account[SIZE];
	int choice;
	char ch;
	double d_amount, w_amount;

	int index = 0;
	do {

		account[index].accept();

		do {
			choice = MenuChoice();
			switch (choice) {
			case 1:
				cout << "Enter how many amount want to be deposit?" << endl;
				cin >> d_amount;
				account[index].deposit(d_amount);
				account[index].displayBalance();
				break;
			case 2:
				cout << "Balance" << endl;
				account[index].displayBalance();
				cout << "Enter withdraw amount" << endl;
				cin >> w_amount;
				account[index].withdraw(w_amount);

				break;
			default:
				break;
			}
			cout << "do you want to perform operation?" << endl;
			cin >> ch;
		} while (ch == 'y');
		index++;
	} while (index != SIZE);

	for (int i = 0; i < index; i++) {
		account[i].display();
	}
	return 0;
}

