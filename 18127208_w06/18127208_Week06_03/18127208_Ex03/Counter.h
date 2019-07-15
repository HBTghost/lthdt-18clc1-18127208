#pragma once
#include <iostream>
#include <stdint.h>

template <class T>
class Counter
{
private:
	static uint16_t count;
public:
	Counter()
	{
		count++;
	}
	Counter(const Counter& c)
	{
		count++;
	}
	~Counter()
	{
		count--;
	}
	static uint16_t GetCount() {
		return count;
	}
};

template<class T> 
uint16_t Counter<T>::count = 0; 
