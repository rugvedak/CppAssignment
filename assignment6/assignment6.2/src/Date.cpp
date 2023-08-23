/*
 * Date.cpp
 *
 *  Created on: 11-Aug-2023
 *      Author: sunbeam
 */

#include <iostream>
#include "../include/Date.h"
using namespace std;
Date::Date() {
}
Date::Date(int mn, int dy, int yr) {
	if (mn > 0 && mn <= monthsPerYear) // validate the month
		month = mn;
	else
		throw invalid_argument("month must be 1-12");

	year = yr; // could validate yr
	day = checkDay(dy); // validate the day

	// output Date object to show when its constructor is called
	cout << "Date object constructor for date ";
	print();
	cout << endl;
}

int Date::getDay() const {
	return day;
}

void Date::setDay(int day) {
	this->day = day;
}

int Date::getMonth() const {
	return month;
}

void Date::setMonth(int month) {
	this->month = month;
}

int Date::getYear() const {
	return year;
}

void Date::setYear(int year) {
	this->year = year;
}

void Date::print() const {
	cout << day << '/' << month << '/' << year;
}

int Date::checkDay(int testDay) const {
	static const int daysPerMonth[monthsPerYear + 1] = { 0, 31, 28, 31, 30, 31,
			30, 31, 31, 30, 31, 30, 31 };

	// determine whether testDay is valid for specified month
	if (testDay > 0 && testDay <= daysPerMonth[month])
		return testDay;

	// February 29 check for leap year
	if (month == 2 && testDay == 29
			&& (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
		return testDay;

	throw invalid_argument("Invalid day for current month and year");
} // end function checkDay

void Date::accept() {
	do {
		cout << "Enter date :: " << endl;
		cout << "Day ::";
		cin >> day;
		cout << "Month ::";
		cin >> month;
		cout << "Year ::";
		cin >> year;
	} while (!validateDate());
}
bool Date::validateDate() {
	int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (year % 4 == 0) {
		months[1] = 29;
	}
	if (!(year >= 100 && year <= 9999)) {
		cout << "invalid year is enterd..";
		return false;
	}
	if (!(month >= 1 && month <= 12)) {
		cout << "invalid month is enterd..";
		return false;
	}
	if (!(day >= 1 && day <= months[month - 1])) {
		cout << "invalid date is enterd..";
		return false;
	}
	return true;
}
bool Date::isleapYear(int yr) {
	if ((yr % 4 == 0) && (yr % 100 != 0))
		return true;
	else if (yr % 400 == 0)
		return true;
	else
		return false;
}
