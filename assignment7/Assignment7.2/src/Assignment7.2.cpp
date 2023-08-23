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
class Product {
protected:
	int id;
	char title[50];
	double price;
public:

	Product() {
		id = 0;
		strcpy(title, "");
		price = 0.0;
	}
	Product(int id, const char *title, double price) {
		this->id = id;
		strcpy(this->title, title);
		this->price = price;
	}
	virtual double calculateDiscount() const = 0;
	double getPrice() const {
		return price - calculateDiscount();
	}
	void display() const {
		cout << "Product: " << title << "\n" << "Price: $" << getPrice()
				<< "\n";
	}
	virtual ~Product() {

	}

};
class Book: public Product {
private:
	char author[50];
public:
	Book() :
			Product() {
		strcpy(this->author, "");
	}
	Book(int id, char *title, double price, char *author) :
			Product(id, title, price) {
		strcpy(this->author, author);
	}

	double calculateDiscount() const override {
		return price * 0.1;
	}
	virtual ~Book() {

	}

};

class Tape: public Product {
private:
	char artist[50];
public:
	Tape() :
			Product() {
		strcpy(this->artist, "");
	}
	Tape(int id, char *title, double price, char *artist) :
			Product(id, title, price) {
		strcpy(this->artist, artist);
	}

	double calculateDiscount() const {
		return price * 0.5;
	}

	virtual ~Tape() {

	}
};

int main() {
	Product *products[3]; // Array to hold 3 products

	for (int i = 0; i < 3; ++i) {
		int choice, id;
		char title[50];
		double price;
		char authorArtist[50];

		cout << "Enter product type (1 for Book, 2 for Tape): ";
		cin >> choice;

		cout << "Enter product ID: ";
		cin >> id;

		cout << "Enter product title: ";
		cin.ignore();
		cin.getline(title, 50);

		cout << "Enter product price: ";
		cin >> price;

		cin.ignore();
		if (choice == 1) {
			cout << "Enter author: ";
		} else {
			cout << "Enter artist: ";
		}
		cin.getline(authorArtist, 50);

		if (choice == 1) {
			products[i] = new Book(id, title, price, authorArtist);
		} else {
			products[i] = new Tape(id, title, price, authorArtist);
		}
	}

	double totalBill = 0.0;

	for (int i = 0; i < 3; ++i) {
		totalBill += products[i]->calculateDiscount();
		delete products[i]; // Deallocate memory
	}

	cout << "Total bill after discounts: $" << totalBill << endl;

	return 0;
}

