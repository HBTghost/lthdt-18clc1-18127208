#include "Student.h"

Student::Student() {
	this->id = "";
	this->FName = "";
	this->LName = "";
	this->address = "";
	this->mark = 0.0;
}
Student::Student(std::ifstream& in) {
	in >> *this;
}
Student::Student(const Student& st) {
	this->id = st.id;
	this->FName = st.FName;
	this->LName = st.LName;
	this->address = st.address;
	this->DoB = st.DoB;
	this->mark = st.mark;	
}
Student::~Student() {}

void Student::input() {
	std::cout << "ID: ";
	getline(std::cin, this->id);
	std::cout << "First name: ";
	getline(std::cin, this->FName);
	std::cout << "Last name: ";
	getline(std::cin, this->LName);
	std::cout << "Address: ";
	getline(std::cin, this->address);
	std::cout << "Day of birth: ";
	getline(std::cin, this->DoB);
	std::cout << "Mark: ";
	std::cin >> this->mark;
	std::cin.ignore();
}

bool Student::isLNameGreater(Student& st) {
	char res = this->LName.compare(st.LName);
	if (res == 1) {
		return true;
	}
	return false;
}

std::ofstream& operator<<(std::ofstream& out, Student& st) {
	out << st.id << "," << st.FName << "," << st.LName << ",";
	out << st.address << "," + st.DoB << "," << st.mark;
	return out;
}
std::ifstream& operator>>(std::ifstream& in, Student& st) {
	getline(in, st.id, ',');
	getline(in, st.FName, ',');
	getline(in, st.LName, ',');
	getline(in, st.address, ',');
	getline(in, st.DoB, ',');
	in >> st.mark;
	std::string temp;
	getline(in, temp);
	return in;
}

void swap(Student& a, Student& b) {
	Student c;
	c = a;
	a = b;
	b = c;
}
