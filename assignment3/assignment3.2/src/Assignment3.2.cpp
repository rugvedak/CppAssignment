//============================================================================
// Name        : 2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define N 2
using namespace std;
class Time {
private:
	int hr, min, sec;
public:
	Time() :
			hr(0), min(0), sec(0) {

	}
	Time(int hr, int min, int sec) :
			hr(hr), min(min), sec(sec) {
	}

	void PrintTime() {
		cout << hr<<":" << min << ":" << sec;
	}

	void acceptTime() {
		cout << "Hour: " << endl;
		cin >> hr;
		cout << "minutes: " << endl;
		cin >> min;
		cout << "Seconds: " << endl;
		cin >> sec;

	}
	int getHr() const {
		return hr;
	}

	void setHr(int hr) {
		this->hr = hr;
	}

	int getMin() const {
		return min;
	}

	void setMin(int min) {
		this->min = min;
	}

	int getSec() const {
		return sec;
	}

	void setSec(int sec) {
		this->sec = sec;
	}
};
int main() {
	int hr, min, sec;
	Time* tarr = (Time*) malloc(sizeof(Time) * N);
	cout << "Enter Time in the form of hr:min:sec" << endl;
	for (int var = 0; var < N; var++) {
		cin >> hr >> min >> sec;
		tarr[var] = (Time(hr, min, sec));
	}

	for (int var = 0;  var< N; var++) {
		tarr[var].PrintTime();
	}

	return 0;
}
