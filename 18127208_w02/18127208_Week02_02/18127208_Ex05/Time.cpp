#include "Time.h"

Time::Time() {
	this->hour = 0;
	this->minute = 0;
	this->second = 0;
}
Time::~Time() {}

void Time::input(int h, int m, int s) {
	this->hour = (h < 0 ? 0 : h % 24);
	this->minute = (m < 0 ? 0 : m % 60);
	this->second = (s < 0 ? 0 : s % 60);
}
void Time::input(int seconds) {
	int h, m, s;
	h = seconds / (60*60);
	m = (seconds - h*60*60) / 60;
	s = seconds - h*60*60 - m*60;
	input(h, m, s);
}
void Time::input() {
	int h, m, s;
	std::cout << "Hour: ";
	std::cin >> h;
	std::cout << "Minute: ";
	std::cin >> m;
	std::cout << "Second: ";
	std::cin >> s;
	input(h, m, s);
}

int Time::getSeconds() {
	return this->hour*60*60 + this->minute*60 + this->second;
}

Time& Time::operator++() {
	int seconds = getSeconds();
	input(++seconds);
	return *this;
}
Time& Time::operator--() {
	int seconds = getSeconds();
	if (seconds > 0) {
		input(--seconds);
	}
	return *this;
}

std::ostream& operator<<(std::ostream& out, Time& time) {
	out << (time.hour>10?"":"0") << time.hour << ":" ;
	out << (time.minute>10?"":"0") << time.minute << ":" ;
	out << (time.second>10?"":"0") << time.second;
	return out;
}
