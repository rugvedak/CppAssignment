//============================================================================
// Name        : cppDateStructure.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
struct Date {
private:
	int day, month, year;
public:
	void initDate() //encapsulation
			{
		day = 1;
		month = 01;
		year = 2000;
	}
	void printDateOnConsole() {
		printf("%d - %d -  %d", day, month, year);
	}
	void acceptDateFromConsole() {
		printf("Enter the date in form of dd-mm-yyyy");
		printf("Enter Day: ");
		scanf("%d", &day);
		printf("Enter Month: ");
		scanf("%d", &month);
		printf("Enter Year: ");
		scanf("%d", &year);
	}

	int MenuChoice() {
		int choice;
		printf("\n 1. Accept Record ");
		printf("\n 2. Print Record\n 0.Exit");
		printf("\n Enter Your choice :: ");
		scanf("%d", &choice);
		return choice;
	}
};

int main() {

	struct Date ptrDate;
	int choice;
	do {
		ptrDate.MenuChoice();

		switch (choice) {
		case 1:
			//accept record
			ptrDate.acceptDateFromConsole();
			break;
		case 2:
			// read  data
			ptrDate.printDateOnConsole();
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
