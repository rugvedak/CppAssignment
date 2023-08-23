//============================================================================
// Name        : 4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "../include/Matrix.h"
using namespace std;
int MenuChoice() {
	int choice;
	cout << "1. Addition " << endl;
	cout << "2. Subtraction" << endl;
	cout << "3. Multiplication" << endl;
	cout << "4. Transpose" << endl;
	cout << "0.Exit" << endl;
	printf("\n Enter Your choice :: ");
	scanf("%d", &choice);
	return choice;
}
int main() {
	int r, c;

	int choice;
	do {

		choice = MenuChoice();
		cout << "Enter rows and columns for first matrix: ";
		cin >> r >> c;

		Matrix fmatrix(r, c);
		Matrix smatrix(r, c);
		Matrix result(r, c);

		//input matrixs data

		switch (choice) {
		case 1:
			fmatrix.accept();
			smatrix.accept();
			cout << "Inputed Matix" << endl;
			cout << "First Matrix " << endl;
			fmatrix.print();
			cout << "Second Matrix " << endl;
			smatrix.print();
			cout << "Addition" << endl;
			result.add(fmatrix, smatrix);
			result.print();
			break;
		case 2:
			fmatrix.accept();
			smatrix.accept();
			cout << "Inputed Matix" << endl;
			cout << "First Matrix " << endl;
			fmatrix.print();
			cout << "Second Matrix " << endl;
			smatrix.print();
			cout << "Subtraction" << endl;
			result.subtract(fmatrix, smatrix);
			result.print();
			break;
		case 3:
			fmatrix.accept();
			smatrix.accept();
			cout << "Inputed Matix" << endl;
			cout << "First Matrix " << endl;
			fmatrix.print();
			cout << "Second Matrix " << endl;
			smatrix.print();

			cout << "Multiplication" << endl;
			result.multiply(fmatrix, smatrix);
			result.print();
			break;
		case 4:
			fmatrix.accept();
			cout << "<Before Transponse Matix" << endl;
			fmatrix.print();
			fmatrix.transponse();
			cout << "Transposed Matrix" << endl;
			fmatrix.print();
			break;
		default:
			cout << "Invalid choice !!";
			continue;
		}

		printf("\n enter 1 to continue or 0 to exit  :: ");
		scanf("%d", &choice);

	} while (choice != 0);
	return 0;
}
