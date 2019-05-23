#pragma once
#include <iostream>
#include <ctime>

class Date
{
public:
	Date();
	~Date();

	void input(int year, int month, int day);
	void input();

	int getYDay();

	int to(Date& date);

private:
	int year, month, day;
};

