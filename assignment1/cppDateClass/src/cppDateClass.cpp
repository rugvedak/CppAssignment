//============================================================================
// Name        : cppDateStructure.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class Date {
private:
	int day, month, year;
public:
	void initDate();
	void printDateOnConsole() {
		cout << day << "-" << month << "-" << year << endl;
	}
	void acceptDateFromConsole() {
		cout << "Enter date :: " << endl;
		cout << "Day ::";
		cin >> day;
		cout << "Month ::";
		cin >> month;
		cout << "Year ::";
		cin >> year;
	}
	bool isleapYear(int yr) {
		if ((yr % 4 == 0) && (yr % 100 != 0))
			return true;
		else if (yr % 400 == 0)
			return true;
		else
			return false;
	}
	int MenuChoice();
};

int MenuChoice() {
	int choice;
	cout << "1. Accept Record " << endl;
	cout << "2. Print Record" << endl;
	cout << "3. Check leap year or not?" << endl;
	cout << "0.Exit" << endl;
	printf("\n Enter Your choice :: ");
	scanf("%d", &choice);
	return choice;
}

int main() {

	class Date dt;
	int choice, yy;
	do {
		choice = MenuChoice();

		switch (choice) {
		case 1:
			//accept record
			dt.acceptDateFromConsole();
			break;
		case 2:
			// read  data
			dt.printDateOnConsole();
			break;
		case 3:
			cout << "To check  given year is leap or not" << endl;
			cin >> yy;
			if (dt.isleapYear(yy) == 1) {
				cout<<yy<<" is leap year"<<endl;
			}
			else if(dt.isleapYear(yy) == 0)
			{
				cout<<yy<<" is not leap year"<<endl;
			}
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
