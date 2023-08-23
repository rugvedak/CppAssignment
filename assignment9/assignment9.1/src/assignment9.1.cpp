//============================================================================
// Name        : 1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include<vector>

using namespace std;
#define SIZE 5
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
	Account(){}
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

	void display() {
		cout << this->id << "\t" << this->type << "\t";
		displayBalance();

	}
	void displayBalance() {
		cout << this->balance << endl;
	}
	void deposit(double amount) {
		balance += amount;
	}

	void withdraw(double amount) {
		if (amount > balance) {
			throw InsufficientFundsException();
		}
		balance -= amount;
	}

	void fundsTransfer(Account &toAccount, double amount) {
		withdraw(amount);
		toAccount.deposit(amount);
	}
};
class Bank: public Account {

private:
	vector<Account> accounts;

public:
	Bank() {
	}
	void accept(int accId) {
		int t;
		accountType type;
		double balance;

		cout << "Account Number  : " << accId;
		cout << "Enter Account Type(SAVING/CURRENT/DMAT) : ";
		cin >> t;
		type = (accountType) t;
		cout << "Initial Balance: ";
		cin >> balance;
		accounts.push_back(Account(accId, type, balance));
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
	void saveToBinaryFile(const char *fileName) {
		ofstream outFile(fileName, ios::binary | ios::out);
		if (!outFile) {
			cerr << "Error opening file for writing." << endl;
			return;
		}

		size_t numAccounts = accounts.size();
		outFile.write(reinterpret_cast<char*>(&numAccounts),
				sizeof(numAccounts));
		for (const auto &account : accounts) {
			outFile.write(reinterpret_cast<const char*>(&account),
					sizeof(account));
		}

		outFile.close();
		cout << "Accounts saved to binary file: " << fileName << endl;
	}

	void loadFromBinaryFile(const char *fileName) {
		ifstream inFile(fileName, ios::binary | ios::in);
		if (!inFile) {
			cerr << "Error opening file for reading." << endl;
			return;
		}

		size_t numAccounts = 0;
		inFile.read(reinterpret_cast<char*>(&numAccounts), sizeof(numAccounts));
		accounts.resize(numAccounts);

		for (auto &account : accounts) {
			inFile.read(reinterpret_cast<char*>(&account), sizeof(account));
		}

		inFile.close();
		cout << "Accounts loaded from binary file: " << fileName << endl;
	}

	void saveToCSVFile(const char *fileName) {
		ofstream outFile(fileName);
		if (!outFile) {
			cerr << "Error opening file for writing." << endl;
			return;
		}

		for (const auto &account : accounts) {
			outFile << account.getId() << "," << account.getType() << ","
					<< account.getBalance() << "\n";
		}

		outFile.close();
		cout << "Accounts saved to CSV file: " << fileName << endl;
	}

};

int main() {
	Bank bank;

	int choice;
	int accId;

	while (true) {
		cout << "\nMenu:\n";
		cout << "1. Accept Account\n";
		cout << "2. Display Account\n";
		cout << "3. Deposit\n";
		cout << "4. Withdraw\n";
		cout << "5. Funds Transfer\n";
		cout << "6. Save Accounts to Binary File\n";
		cout << "7. Load Accounts from Binary File\n";
		cout << "8. Save Accounts to CSV File\n";
		cout << "9. Exit\n";
		cout << "Enter choice: ";
		cin >> choice;

		if (choice == 9) {
			break;
		}

		cout << "Enter account ID: ";
		cin >> accId;

		switch (choice) {
		case 1:
			bank.accept(accId);
			break;
		case 2:
			bank.display(accId);
			break;
		case 3: {
			double amount;
			cout << "Enter amount to deposit: ";
			cin >> amount;
			bank.deposit(accId, amount);
			break;
		}
		case 4: {
			double amount;
			cout << "Enter amount to withdraw: ";
			cin >> amount;
			bank.withdraw(accId, amount);
			break;
		}
		case 5: {
			int toAccId;
			double amount;
			cout << "Enter recipient account ID: ";
			cin >> toAccId;
			cout << "Enter amount to transfer: ";
			cin >> amount;
			bank.fundsTransfer(accId, toAccId, amount);
			break;
		}
		case 6: {
			char fileName[50];
			cout << "Enter binary file name: ";
			cin.ignore();
			cin.getline(fileName,50);
			bank.saveToBinaryFile(fileName);
			break;
		}
		case 7: {
			char fileName[50];
			cout << "Enter binary file name: ";
			cin.ignore();
			cin.getline(fileName,50);
			bank.loadFromBinaryFile(fileName);
			break;
		}
		case 8: {
			char fileName[50];
			cout << "Enter CSV file name: ";
			cin.ignore();
			cin.getline(fileName,50);
			bank.saveToCSVFile(fileName);
			break;
		}
		default:
			cout << "Invalid choice." << endl;
		}
	}
	return 0;
}
