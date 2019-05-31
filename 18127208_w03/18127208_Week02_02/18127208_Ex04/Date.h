#pragma once
#include <iostream>
#include <ctime>

class Date
{
public:
	Date();
	Date(int year, int month, int day);
	Date(tm date);
	~Date();

	void input(tm date);
	void input();

	tm& getTM();

	Date& operator++();
	Date& operator--();

	friend std::ostream& operator<<(std::ostream& out, Date& date);

private:
	int year, month, day;
};

