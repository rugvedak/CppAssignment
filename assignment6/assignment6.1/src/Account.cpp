/*
 * Account.cpp
 *
 *  Created on: 10-Aug-2023
 *      Author: sunbeam
 */
#include<iostream>
#include "../include/Account.h"

using namespace std;
class InsufficientFundsException: public std::exception {
private:
	int id;
	double cur_balance;
	double w_amount;
public:
	InsufficientFundsException() {
	}
	InsufficientFundsException(int, double, double) {

	}
	const char* what() const noexcept override {
		return "Insufficient funds.";
	}

};

Account::Account() :
		id(genarateAccNo++), type(SAVING), balance(0) {
}

inline double Account::getBalance() const {
	return balance;
}

inline int Account::getId() const {
	return id;
}
//
//inline void Account::setId(int id) {
//	this->id = id;
//}
int Account::genarateAccNo = 1;
inline accoutType Account::getType() const {
	return type;
}

inline void Account::setType(accoutType type) {
	this->type = type;
}

void Account::accept() {
	int t;
	cout << "Enter Account Type(SAVING/CURRENT/DMAT) : ";
	cin >> t;
	type = (accoutType) t;
	cout << "Initial Balance: ";
	cin >> this->balance;
}
void Account::display() {
	cout << "Account Number  : " << this->id << endl;
	cout << "Account Type    : " << this->type << endl;
	cout << "Initial Balance : ";
	displayBalance();

}
void Account::displayBalance() {
	cout << this->balance << endl;
}

void Account::deposit(double amount) {
	this->balance += amount;

}
void Account::withdraw(double amount) {

	if (amount > balance) {
		throw InsufficientFundsException();
		;
	} else {
		balance = balance - amount;
		cout << amount << " is withdrawn from the account.";
	}

}
