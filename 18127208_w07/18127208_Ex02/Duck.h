#pragma once
#include <iostream>

class Duck
{
protected:
	Duck() {
		std::cout << "Duck()...\n";
	}
public:
	static Duck& getInstance()	{
		static Duck duck;
		return duck;
	}
	Duck(Duck const&) = delete;
	Duck(Duck&&) = delete;
	Duck& operator=(Duck const&) = delete;
	Duck& operator=(Duck &&) = delete;
};