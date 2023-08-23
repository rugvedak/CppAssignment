/*
 * Date.h
 *
 *  Created on: 11-Aug-2023
 *      Author: sunbeam
 */

#ifndef DATE_H_
#define DATE_H_

class Date {
private:
	int month; // 1-12 (January-December)
	int day; // 1-31 based on month
	int year; // any year
	// utility function to check if day is proper for month and year
	int checkDay(int) const;
public:
	static const int monthsPerYear = 12; // number of months in a year
	Date();
	Date(int, int, int); // default constructor
	void print() const;
	int getDay() const;
	void setDay(int day);
	int getMonth() const;
	void setMonth(int month);
	int getYear() const;
	void setYear(int year);
	void accept();
	bool isleapYear(int);
	bool validateDate();
};

#endif /* DATE_H_ */
