#pragma once
#include "CFile.h"
#include <vector>

class CFolder : public CItem
{
public:
	explicit CFolder(std::string name, uint64_t size = 0) : name{name}, size{size} {}

	void add(CFile* cFile) {
		CItem* x = new CFile(*cFile);
		cItems.emplace_back(x);
	}
	void add(CFolder* cFolder) {
		CItem* x = new CFolder(*cFolder);
		cItems.emplace_back(x);
	}
	void print() {
		std::cout << name << std::endl;
	}
	void print(bool flag) override {
		if (!isHided) {
			print();
			if (!hideAll) {
				for (auto x : cItems) {
					x->print(flag);
				}
			}
		}
	}
	CItem* removeByName(std::string name) {
		CItem* res = findByName(name);
		for (uint16_t i = 0; i < cItems.size(); ++i) {
			if (cItems[i] == res) {
				cItems.erase(cItems.begin() + i);
				break;
			}
		}
		return res;
	} 
	CItem* findByName(std::string name) {
		if (this->name == name) {
				return this;
		}
		for (auto x : cItems) {
			CItem* res = x->findByName(name);
			if (res != nullptr) {
				return res;
			}
		}
		return nullptr;
	} 
	void setHidden(bool flag, bool all) override {
		isHided = flag;
		hideAll = all;
	}

	
private:
	std::string name{""};
	uint64_t size{ 0 };
	bool isHided{ false };
	bool hideAll{ false };
	std::vector<CItem*> cItems;
};
