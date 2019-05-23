#include "Date.h"

int main(int argc, char const* argv[])
{
	tm ltm;
	time_t now = time(0);
	localtime_s(&ltm, &now);

	Date recent, input;
	recent.input(1900 + ltm.tm_year, 1 + ltm.tm_mon, ltm.tm_mday);
	input.input();

	int delta = input.to(recent);
	std::cout << "The distance from this date to current date: " << delta << " day";
	if (delta > 1)
		std::cout << "s\n";
	else
		std::cout << "\n";
	return 0;
}