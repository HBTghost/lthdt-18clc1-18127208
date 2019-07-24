#pragma once
#include "CItem.h"

class CFile : public CItem
{
public:
	CFile(std::string name, uint64_t size)
		: name{name}, size{size} {}
	virtual ~CFile() = default;

	void print(bool flag) override {
		if (!isHided) {
			std::cout << name << std::endl;
		}
	}
	void setHidden(bool flag, bool all) override {
		isHided = flag;
	}
	CItem* findByName(std::string name) {
		if (this->name == name) {
			return this;
		}
		return nullptr;
	}
	
private:
	std::string name{ "" };
	uint64_t size{ 0 };
	bool isHided{ false };
};
