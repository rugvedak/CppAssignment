/*
 ============================================================================
 Name        : CDateStructure.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Write a menu driven program for Date in a C and CPP language.
 Declare a structure Date having data members day, month, year.
 Implement the following functions.
 void initDate(struct Date* ptrDate);
 void printDateOnConsole(struct Date* ptrDate);
 void acceptDateFromConsole(struct Date* ptrDate);
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct Date {
	int day, month, year;
};
void initDate(struct Date *ptrDate);
void printDateOnConsole(struct Date *ptrDate);
void acceptDateFromConsole(struct Date *ptrDate);
int MenuChoice();

void initDate(struct Date *ptrDate) {
	ptrDate->day = 1;
	ptrDate->month = 01;
	ptrDate->year = 2000;
}
void printDateOnConsole(struct Date *ptrDate) {
	printf("%d - %d -  %d", ptrDate->day, ptrDate->month, ptrDate->year);
}
void acceptDateFromConsole(struct Date *ptrDate) {
	printf("Enter the date in form of dd-mm-yyyy\n");
	printf("Enter Day: ");
	scanf("%d", &ptrDate->day);
	printf("Enter Month between 1 to 31: ");
	scanf("%d", &ptrDate->month);
	printf("Enter Year upto 2023: ");
	scanf("%d", &ptrDate->year);
}
int MenuChoice() {
	int choice;
	printf("\n 1. Accept Date ");
	printf("\n 2. Print Date");
	printf("\n 0.Exit");
	printf("\n Enter Your choice :: ");
	scanf("%d", &choice);
	return choice;
}
int main(void) {

struct Date ptrDate;
	int choice;
	do {
		choice = MenuChoice();

		switch (choice) {
		case 1:
			//accept record
			acceptDateFromConsole(&ptrDate);
			break;
		case 2: // read data
			printDateOnConsole(&ptrDate);
			break;
		default:
			printf("\n invalid choice:: ");
			continue;
		}

		printf("\n enter 1 to continue or 0 to exit  :: ");
		scanf("%d", &choice);

	} while (choice != 0);
	return 0;
}
