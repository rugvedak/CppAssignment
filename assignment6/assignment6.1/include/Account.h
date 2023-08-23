/*
 * Account.h
 *
 *  Created on: 10-Aug-2023
 *      Author: sunbeam
 */

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

enum accoutType
{
	SAVING=1,CURRENT=2,DMAT=3
};

class Account
{
private:
	const int id;
	accoutType type;
	double balance;
	static int genarateAccNo;
public:
	Account();
	void accept();
	void display();
	void deposit(double);
	void withdraw(double);
	double getBalance() const;
	int getId() const;
	void setId(int id);
	accoutType getType() const;
	void setType(accoutType type);
	void displayBalance();
};


#endif /* ACCOUNT_H_ */
