//============================================================================
// Name        : 2.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
class Product
{
private:
	int id;
	char title[50];
	double price;

protected:
	char type;

public:
	Product()
	{
		id = 0;
		strcpy(title, "");
		price = 0.0;
	}
	Product(int id, const char title[], double price)
	{
		this->id = id;
		strcpy(this->title, title);
		this->price = price;
	}
	virtual void calculateDiscount() = 0;
	double getPrice()
	{
		return price;
	}

	void setPrice(double p)
	{
		price = p;
	}
	char getType()
	{
		return type;
	}

	// void display() const
	// {
	// 	cout << "Product: " << title << "\n"
	// 		 << "Price: $" << getPrice
	// 		 << "\n";
	// }
	virtual ~Product()
	{
	}
};
class Book : public Product
{
private:
	char author[50];

public:
	Book() : Product()
	{
		this->type = 'B';
		strcpy(this->author, "");
	}
	Book(int id, char title[], double price, char author[]) : Product(id, title, price)
	{
		this->type = 'B';
		strcpy(this->author, author);
	}

	void calculateDiscount() override
	{
		setPrice(getPrice() * 0.9);
	}
	virtual ~Book()
	{
	}
};

class Tape : public Product
{
private:
	char artist[50];

public:
	Tape() : Product()
	{

		this->type = 'T';
		strcpy(this->artist, "");
	}
	Tape(int id, char title[], double price, char artist[]) : Product(id, title, price)
	{

		this->type = 'B';
		strcpy(this->artist, artist);
	}

	void calculateDiscount() override
	{
		setPrice(getPrice() * 0.95);
	}

	virtual ~Tape()
	{
	}
};

int main()
{
	const int maxProducts = 3;
	Product *cart[maxProducts];
	int choice;

	for (int i = 0; i < maxProducts; i++)
	{
		cout << "Menu:" << endl;
		cout << "1. Add Book" << endl;
		cout << "2. Add Tape" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		int id;
		char title[20];
		char author[20];
		char artist[20];
		double price;

		switch (choice)
		{
		case 1:

			cout << "Enter Book ID: ";
			cin >> id;
			cout << "Enter Title: ";
			cin.ignore();
			cin.getline(title, 20);
			cout << "Enter Author: ";
			cin.getline(author, 20);
			cout << "Enter Price: $";
			cin >> price;
			cart[i] = new Book(id, title, price, author);
			cart[i]->calculateDiscount();
			break;

		case 2:

			cout << "Enter Tape ID: ";
			cin >> id;
			cout << "Enter Title: ";
			cin.ignore();
			cin.getline(title, 20);
			cout << "Enter Artist: ";
			cin.getline(artist, 20);
			cout << "Enter Price: $";
			cin >> price;
			cart[i] = new Tape(id, title, price, artist);
			cart[i]->calculateDiscount();
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
			//i--; // Decrement 'i' to try again
			break;
		}
	}
	double total_bill = 0.0;
	double total_book_bill = 0.0;
	double total_tape_bill = 0.0;

	for (int i = 0; i < maxProducts; i++)
	{
		if (cart[i]->getType() == 'B')
			total_book_bill = total_book_bill + cart[i]->getPrice();
	}

	for (int i = 0; i < maxProducts; i++)
	{
		if (cart[i]->getType() == 'T')
			total_tape_bill = total_tape_bill + cart[i]->getPrice();
	}

	for (int i = 0; i < maxProducts; i++)
	{
		total_bill += cart[i]->getPrice();
	}

	cout << "Final bill: $" << total_bill << endl;

	for (int i = 0; i < maxProducts; i++)
	{
		if (cart[i] != nullptr)
		{
			delete cart[i];
		}
	}
	return 0;
}
