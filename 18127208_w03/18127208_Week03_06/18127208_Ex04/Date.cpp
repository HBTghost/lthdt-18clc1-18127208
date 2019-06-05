#include "Date.h"

Date::Date() {
	this->year = 1;
	this->month = 1;
	this->day = 1;
}
Date::Date(tm date) {
	input(date);
}
Date::Date(int year, int month, int day) {
	this->year = year;
	this->month = month;
	this->day = day;
}
Date::~Date() {}

void Date::input(tm date) {
	this->year = date.tm_year + 1900;
	this->month = date.tm_mon + 1;
	this->day = date.tm_mday;
}
void Date::input() {
	std::cout << "Day: ";
	std::cin >> this->day;
	std::cout << "Month: ";
	std::cin >> this->month;
	std::cout << "Year: ";
	std::cin >> this->year;
}

tm& Date::getTM() {
	tm date = {};
	date.tm_year = this->year - 1900;
	date.tm_mon = this->month - 1;
	date.tm_mday = this->day;
	mktime(&date);
	return date;
}

Date& Date::operator++() {
	this->day++;
	tm date = getTM();
	input(date);
	return *this;
}
Date& Date::operator--() {
	this->day--;
	tm date = getTM();
	input(date);
	return *this;
}

std::ostream& operator<<(std::ostream& out, Date& date) {
	out << date.day << "/" << date.month << "/" << date.year;
	return out;
}
