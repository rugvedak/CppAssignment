//============================================================================
// Name        : 1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class Box {
	double length, width, height;
	double volume;
public:
	Box() {
		length = 0;
		width = 0;
		height = 0;
	}
	void acceptBoxData() {
		cout << "Length: " << endl;
		cin >> length;
		cout << "Width: " << endl;
		cin >> width;
		cout << "Height: " << endl;
		cin >> height;
	}
	double calculateVolumeBox() {
		volume = length * width * height;
		return volume;
	}
	void printBoxVolume() {
		cout << "Length: " << length << endl;
		cout << "Width: " << width << endl;
		cout << "Height: " << height << endl;
		cout << "Volume of Box: " << calculateVolumeBox();
	}

};
int MenuChoice() {
	int choice;
	cout << "1. Accept Box Dimensions " << endl;
	cout << "2. Print Volume of Box" << endl;
	cout << "0.Exit" << endl;
	printf("\n Enter Your choice :: ");
	scanf("%d", &choice);
	return choice;
}

int main() {

	Box b;
	int choice;
	do {
		choice = MenuChoice();

		switch (choice) {
		case 1:
			//accept box dimensions
			b.acceptBoxData();
			break;
		case 2:
			// read  data
			b.printBoxVolume();
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
