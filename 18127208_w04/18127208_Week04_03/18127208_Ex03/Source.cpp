#include "IntArr.h"

int main(int argc, char const *argv[])
{
	// Using dynamic allocated array
	IntArr m1;
	IntArr m2(7);
	int a[100];
	int n = 7;
	for (int i = 0; i < n; i++)
	{
		a[i] = i * 2 / 7;
	}
	IntArr m3(a, n);
	IntArr m4(m2);
	IntArr m5;
	m5 = m2;

	std::cin >> m2;
	std::cout << m2 << "\n";

	std::cout << m3[6] << "\n";
	m3[6] = 1;

	std::cout << (int)m4 << "\n";
	return 0;
}