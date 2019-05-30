#pragma once
#include <iostream>

class Time
{
public:
	Time();
	~Time();

	void input(int h, int m, int s);
	void input(int seconds);
	void input();

	int getSeconds();

	Time& operator++();
	Time& operator--();

	friend std::ostream& operator<<(std::ostream& out, Time& time);

private:
	int hour, minute, second;
};

