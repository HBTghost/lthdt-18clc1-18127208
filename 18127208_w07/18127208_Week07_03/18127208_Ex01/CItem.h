#pragma once
#include <iostream>
#include <string>
#include <stdint.h>

class CItem
{
public:
	virtual ~CItem() = default;

	virtual void print(bool flag) = 0;
	virtual void setHidden(bool flag, bool all) = 0;
	virtual CItem* findByName(std::string name) = 0;
};
