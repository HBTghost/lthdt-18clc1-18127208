#pragma once
#include <iostream>

template <class T>
class Counter
{
private:
	static int count;
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
	static int GetCount() {
		return count;
	}
};

template<class T> 
int Counter<T>::count = 0; 

// class MyClass : private Counter<MyClass>
// {
//    public:
//       using Counter<MyClass>::GetCount;
// }