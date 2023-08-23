//============================================================================
// Name        : 4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define SIZE 2
using namespace std;
enum accountType {
	SAVING = 1, CURRENT = 2, DMAT = 3
};
class InsufficientFundsException: public exception {

public:
	InsufficientFundsException() {

	}

	const char* display() const throw () {
		return "Insufficient Balance!";
	}

};

class Account {
private:
	int id;
	accountType type;
	double balance;

public:
	Account() {
	}
	Account(int id, accountType type, int balance) {
		this->id = id;
		this->type = type;
		this->balance = balance;
	}

	double getBalance() const {
		return balance;
	}

	void setBalance(double balance) {
		this->balance = balance;
	}

	const int getId() const {
		return id;
	}

	accountType getType() const {
		return type;
	}

	void setType(accountType type) {
		this->type = type;
	}
	void accept() {
		int t;
		cout << "Enter Account Number  : ";
		cin >> id;
		cout << "Enter Account Type(SAVING/CURRENT/DMAT) : ";
		cin >> t;
		type = (accountType) t;
		cout << "Initial Balance: ";
		cin >> this->balance;
	}
	void display() {
		cout << this->id << "\t" << this->type << "\t";
		displayBalance();

	}
	void displayBalance() {
		cout << this->balance << endl;
	}

	void deposit(double amount) {
		this->balance += amount;

	}
	void withdraw(double amount) {
		try {
			if (amount > balance) {
				InsufficientFundsException obj;
				throw obj;
			} else {
				balance = balance - amount;
				cout << amount << " is withdrawn from the account.";
			}
		} catch (InsufficientFundsException &e) {
			cout << e.display();
		}
	}
};

class Bank: public Account {
private:
	Account accounts[SIZE];

public:
	Bank() {
	}
	void openAccount() {
		for (int i = 0; i < SIZE; i++) {
			accounts[i].accept();
		}
	}
	void display(int accId) {
		for (int i = 0; i < SIZE; i++) {
			if (accounts[i].getId() == accId) {
				cout << "Account ID: " << accId << ", Balance: "
						<< accounts[i].getBalance() << endl;
				return;
			}
		}
		cout << "Account not found." << endl;
	}
	void displayAllAccount() {
		cout << "AccNO\tAccType\tBalance" << endl;
		for (int i = 0; i < SIZE; i++) {
			accounts[i].display();
		}
	}

	void deposit(int accId, double amount) {
		for (int i = 0; i < SIZE; i++) {
			if (accounts[i].getId() == accId) {
				accounts[i].deposit(amount);
				cout << "Deposited " << amount << " into Account ID " << accId
						<< endl;
				return;
			}
		}
		cout << "Account not found." << endl;
	}

	void withdraw(int accId, double amount) {
		for (int i = 0; i < SIZE; i++) {
			if (accounts[i].getId() == accId) {
				try {
					accounts[i].withdraw(amount);
					cout << "Withdrawn " << amount << " from Account ID "
							<< accId << endl;
				} catch (const runtime_error &e) {
					cout << "Withdrawal error: " << e.what() << endl;
				}
				return;
			}
		}
		cout << "Account not found." << endl;
	}

	void fundsTransfer(int fromAccId, int toAccId, double amount) {
		for (int i = 0; i < SIZE; i++) {
			if (accounts[i].getId() == fromAccId) {
				try {
					accounts[i].withdraw(amount);
				} catch (const runtime_error &e) {
					cout << "Withdrawal error: " << e.what() << endl;
					return;
				}
			}
			if (accounts[i].getId() == toAccId) {
				accounts[i].deposit(amount);
				cout << "Transferred " << amount << " from Account ID "
						<< fromAccId << " to Account ID " << toAccId << endl;
				return;
			}
		}
		cout << "One or both accounts not found." << endl;
	}

};
int MenuChoice() {
	int choice;
	cout<<"\n 1. Deposit ";
	cout<<"\n 2. Withdraw";
	cout<<"\n 3. Fund Transfer";
	cout<<"\n Enter Your choice :: ";
	cin>>choice;
	return choice;
}
int main() {
	Bank bank;
	bank.openAccount();
	bank.displayAllAccount();

	int choice;
	char ch;
	do {
		int accNo;
		double amount;

		choice = MenuChoice();
		switch (choice) {
		case 1:
			cout << "Enter Account No " << endl;
			cin >> accNo;
			cout << "Enter how many amount want to be deposit?" << endl;
			cin >> amount;
			bank.deposit(accNo, amount);
			bank.display(accNo);
			break;
		case 2:
			cout << "Enter Account No " << endl;
			cin >> accNo;
			bank.display(accNo);
			cout << "Enter withdraw amount" << endl;
			cin >> amount;
			bank.withdraw(accNo, amount);
			bank.display(accNo);
			break;
		case 3:
			int fromAccount, toAccount;
			cout << "Enter Account No  where from amount will transfer? "
					<< endl;
			cin >> fromAccount;
			cout << "Enter Account No  where to amount will transfered? "
					<< endl;
			cin >> toAccount;
			cout << "Enter how many amount want to be deposit?" << endl;
			cin >> amount;
			bank.fundsTransfer(fromAccount, toAccount, amount);
			bank.display(fromAccount);
			bank.display(toAccount);
			break;
		default:
			break;
		}
		cout << "do you want to perform operation?" << endl;
		cin >> ch;
	} while (ch == 'y');
	return 0;
}
