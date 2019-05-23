#include "Student.h"

Student::Student() {
	this->id = "";
	this->name = "";
	this->gender = "";
	this->address = "";
	this->mark = 0.0;
}
Student::~Student() {}

void Student::input() {
	std::cout << "ID: ";
	getline(std::cin, this->id);
	std::cout << "Full name: ";
	getline(std::cin, this->name);
	std::cout << "Gender: ";
	getline(std::cin, this->gender);
	std::cout << "Address: ";
	getline(std::cin, this->address);
	std::cout << "Mark: ";
	std::cin >> this->mark;
	std::cin.ignore();
}

char Student::getGPA() {
	if (this->mark > 3) {
		return 'A';
	}
	else if (this->mark > 2) {
		return 'B';
	}
	else if (this->mark > 1) {
		return 'C';
	}
	else if (this->mark > 0) {
		return 'D';
	}
	else {
		return 'F';
	}
}
std::string Student::getClass() {
	return this->id.substr(0, 2);
}

bool Student::hasGreaterMark(Student& st) {
	return this->mark > st.mark;
}

std::ofstream& operator<<(std::ofstream& out, Student& st) {
	out << st.id << "," << st.name << "," << st.getClass() << "," + st.address << ",";
	out << st.mark << "," << st.getGPA();
	return out;
}