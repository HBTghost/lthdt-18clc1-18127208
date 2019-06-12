#include "Date.h"

Date::Date() {
	tm ltm;
	time_t now = time(0);
	localtime_s(&ltm, &now);
	input(ltm);
}
Date::Date(int year) {
	this->year = year;
	this->month = 1;
	this->day = 1;
}
Date::Date(int year, int month) {
	this->year = year;
	this->month = month;
	this->day = 1;
}
Date::Date(int year, int month, int day) {
	this->year = year;
	this->month = month;
	this->day = day;
}
Date::Date(const Date& date) {
	*this = date;
}
Date::Date(tm date) {
	input(date);
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

tm Date::getTM() const{
	tm date = {};
	date.tm_year = this->year - 1900;
	date.tm_mon = this->month - 1;
	date.tm_mday = this->day;
	mktime(&date);
	return date;
}

Date Date::Tomorrow() {
	return *this + 1;
}
Date Date::Yesterday() {
	return *this - 1;
}

Date& Date::operator=(const Date& date) {
	input(date.getTM());
	return *this;
}

Date& Date::operator+=(int days) {
	return *this = *this + days;
}
Date& Date::operator-=(int days) {
	return *this = *this - days;
}

Date& Date::operator++() {
	return *this = *this + 1;
}
Date Date::operator++(int) {
	*this = *this + 1;
	return *this - 1;
}
Date& Date::operator--() {
	return *this = *this - 1;
}
Date Date::operator--(int) {
	*this = *this - 1;
	return *this + 1;
}

Date::operator int() {
	return getTM().tm_yday;
}
Date::operator long() {
	Date date(1, 1, 1);
	long sum = 0;
	int start = date.year;
	int end = this->year;
	for (int i = start; i < end; ++i) {
		if ((i % 400 == 0) || (((i % 4) == 0) && ((i % 100) != 0))) sum += 366;
		else sum += 365;
	}
	return sum + date.getTM().tm_yday - getTM().tm_yday;
}

Date operator+(Date date, int days) {
	date.day += days;
	date.input(date.getTM());
	return date;
}
Date operator-(Date date, int days) {
	date.day -= days;
	date.input(date.getTM());
	return date;
}
std::ostream& operator<<(std::ostream& out, Date date) {
	out << date.day << "/" << date.month << "/" << date.year;
	return out;
}
std::istream& operator>>(std::istream& in, Date& date) {
	in >> date.year;
	in >> date.month;
	in >> date.day;
	return in;
}
bool operator==(Date& a, Date& b) {
	return (a.year == b.year && a.getTM().tm_yday == b.getTM().tm_yday);
}
bool operator!=(Date& a, Date& b) {
	return !(a==b);
}
bool operator>(Date& a, Date& b) {
	if (a.year >= b.year) {
		if (a.year > b.year || a.getTM().tm_yday > b.getTM().tm_yday) {
			return true;
		}
	}
	return false;
}
bool operator>=(Date& a, Date& b) {
	if (a.year >= b.year) {
		if (a.year > b.year || a.getTM().tm_yday >= b.getTM().tm_yday) {
			return true;
		}
	}
	return false;
}
bool operator<(Date& a, Date& b) {
	return !(a>=b);
}
bool operator<=(Date& a, Date& b) {
	return !(a>b);
}
