//============================================================================
/*Write a menu driven program for Student management. In
main(), create Array of Objects and provide facility for accept, print,
search and sort.
For student accept name, gender, rollNumber and marks of three
subjects from user and print name, rollNumber, gender and
percentage.
Provide global functions void sortRecords(Studuent[] arr) and int
searchRecords(Student[] arr) for sorting and searching array. Search
function returns index of found Student, otherwise returns -1.*/
//============================================================================

#include <iostream>
#include "../include/Student.h"
using namespace std;

void sortRecords(Student[], int);
int searchRecords(Student[], int);
int main() {
	Student student[30];
	int n, i;
	cout << "Enter Number of Students - ";
	cin >> n;
	// Accessing the function
	for (i = 0; i < n; i++)
		student[i].acceptStudent();

	cout << "Student Data - " << endl;

	// Accessing the function
	for (i = 0; i < n; i++)
		student[i].printStudent();

	cout<<"----------------Sort Student --------------------------"<<endl;
	sortRecords(student, n);
	cout<<"----------------Search Student --------------------------"<<endl;
	int result = searchRecords(student, n);
	if (result == -1)
		cout << "Student Record not found" << endl;
	else if (result == 1)
		cout << "Student Record found" << endl;
	return 0;
}

void sortRecords(Student arr[], int n) {
	int choice, i;
	Student temp;
	cout << "On what basis you want to sort student(1.Roll Number/2.Marks)";
	cin >> choice;

	switch (choice) {
	case 1:
		for (i = 0; i < n-1; i++) {
			for (int j = i + 1; j < n; j++)
				if (arr[i].getRollNumber() > arr[j].getRollNumber()) {
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
		}
		for (int i = 0; i < n; i++)
			arr[i].printStudent();
		break;
	case 2:
		for (i = 0; i < n-1; i++) {
			for (int j = i + 1; j < n; j++)
				if (arr[i].getPercentage() > arr[j].getPercentage()) {
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
		}
		for (int i = 0; i < n; i++)
			arr[i].printStudent();
		break;
	default:
		break;
	}
}
int searchRecords(Student arr[], int n) {
	int search, b=0;
	cout << "Enter Student Roll Number do you want to seach?" << endl;
	cin >> search;

	for (int var = 0; var < n; var++) {
		if (arr[var].getRollNumber() == search) {
			b = 1;
			arr[var].printStudent();
			return 1;
		}
	}
	if (b == 0) {
		return -1;
	}
	return -1;
}

