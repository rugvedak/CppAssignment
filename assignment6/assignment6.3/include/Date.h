/*
 * Date.h
 *
 *  Created on: 16-Aug-2023
 *      Author: sunbeam
 */

#ifndef DATE_H_
#define DATE_H_

class Date {
	int month; // 1-12 (January-December)
	int day; // 1-31 based on month
	int year; // any year
    // utility function  because any month contain 28 30 31 days.
	int checkDay(int) const;
public:
	//utility data member use for valdatation purpose 
	static const int monthsPerYear = 12;
	Date();
	Date(int, int, int); // default constructor
	void print() const;
	int getDay() const;
	void setDay(int day);
	int getMonth() const;
	void setMonth(int month);
	int getYear() const;
	void setYear(int year);
	//to get from user 
	void accept();
	bool isleapYear(int);
	//utility function to check user inputed validate date or not
	bool validateDate();
};

#endif /* DATE_H_ */
