#include "Date.h"

Date::Date() {
	this->year = 1;
	this->month = 1;
	this->day = 1;
}
Date::~Date() {}

void Date::input(int year, int month, int day) {
	this->year = year;
	this->month = month;
	this->day = day;
}
void Date::input() {
	std::cout << "Day: ";
	std::cin >> this->day;
	std::cout << "Month: ";
	std::cin >> this->month;
	std::cout << "Year: ";
	std::cin >> this->year;
}

int Date::getYDay() {
	tm date = {};
	date.tm_year = this->year - 1900;
	date.tm_mon = this->month - 1;
	date.tm_mday = this->day;
	mktime(&date);
	return date.tm_yday;
}

int Date::to(Date& date) {
	int sum = 0;
	int start, end;
	if (this->year < date.year) {
		start = this->year;
		end = date.year;
	}
	else {
		start = date.year;
		end = this->year;
	}
	for (int i = start; i < end; ++i) {
		if ((i % 400 == 0) || (((i % 4) == 0) && ((i % 100) != 0))) sum += 366;
		else sum += 365;
	}
	return sum + date.getYDay() - getYDay();
}
