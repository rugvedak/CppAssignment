//============================================================================
// Name        : 3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<list>
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
	list<Account> accountList;
	int numAccouonts;

public:
	Bank() {
	}

	int getNumAccouonts() const {
		return numAccouonts;
	}

	void setNumAccouonts(int numAccouonts) {
		this->numAccouonts = numAccouonts;
	}

	void openAccount() {
		int t, id;
		accountType type;
		double balance;
		cout << "Enter How many account do you want into add?" << endl;
		cin >> numAccouonts;
		for (int i = 0; i < numAccouonts; i++) {
			cout << "Enter Account Number  : ";
			cin >> id;
			cout << "Enter Account Type(SAVING/CURRENT/DMAT) : ";
			cin >> t;
			type = (accountType) t;
			cout << "Initial Balance: ";
			cin >> balance;
			accountList.push_back(Account(id, type, balance));
		}
	}
	// displaying  all accounts in Forword direction
	void displayAllAccount() {
		for (const auto &account : accountList) {
			cout << account.getId() << "," << account.getType() << ","
					<< account.getBalance();
		}
	}
	void displayRrecordByID(int accId) {

		for (const auto &account : accountList) {
			if (account.getId() == accId) {
				cout << accId << "\t" << account.getType() << "\t"
						<< account.getBalance() << endl;
				return;
			}
		}
		cout << "Account not found." << endl;
	}

	void deposit(int accId, double amount) {
		for (auto &account : accountList) {
			if (account.getId() == accId) {
				account.deposit(amount);
				cout << "Deposited " << amount << " into Account ID " << accId
						<< endl;
				return;
			}
		}
		cout << "Account not found." << endl;
	}
	void withdraw(int accId, double amount) {
		for (auto &account : accountList) {
			if (account.getId() == accId) {
				account.withdraw(amount);
				cout << "Withdrawn " << amount << " from Account ID " << accId
						<< endl;
				return;
			}
		}
		cout << "Account not found." << endl;
	}

	void fundsTransfer(int fromAccId, int toAccId, double amount) {
		Account *fromAccount = nullptr;
		Account *toAccount = nullptr;

		for (auto &account : accountList) {
			if (account.getId() == fromAccId) {
				fromAccount = &account;
			}
			if (account.getId() == toAccId) {
				toAccount = &account;
			}
		}

		if (fromAccount && toAccount) {
			fromAccount->withdraw(amount);
			toAccount->deposit(amount);
			cout << "Transferred $" << amount << " from Account ID "
					<< fromAccId << " to Account ID " << toAccId << endl;

		} else {
			cout << "One or both accounts not found." << endl;
		}
	}

};
int MenuChoice() {
	int choice;
	cout << "\n 1. Deposit ";
	cout << "\n 2. Withdraw";
	cout << "\n 3. Fund Transfer";
	cout << "\n Enter Your choice :: ";
	cin >> choice;
	return choice;
}

int main() {
	Bank bank;

	int choice;
	char ch;
	do {
		int accNo;
		double amount;

		bank.openAccount();
		choice = MenuChoice();

		switch (choice) {
		case 1:
			cout << "Enter Account No " << endl;
			cin >> accNo;
			cout << "Enter how many amount want to be deposit?" << endl;
			cin >> amount;
			bank.deposit(accNo, amount);
			bank.displayRrecordByID(accNo);
			break;
		case 2:
			cout << "Enter Account No " << endl;
			cin >> accNo;
			bank.displayRrecordByID(accNo);
			cout << "Enter withdraw amount" << endl;
			cin >> amount;
			bank.withdraw(accNo, amount);
			bank.displayRrecordByID(accNo);
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
			bank.displayRrecordByID(fromAccount);
			bank.displayRrecordByID(toAccount);
			break;
		default:
			break;
		}
		cout << "do you want to perform operation?" << endl;
		cin >> ch;
	} while (ch == 'y');
	return 0;

}
