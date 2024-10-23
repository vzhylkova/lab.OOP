#include "Person.h"
#include <string>
#include <iostream>

using namespace personNamespace;
Person::Person()
	: name("Unknown"), age(0), surname("Unknown"), middlename("Unknown"), birthDate("Unknown") {
}

Person::Person(const string& name, int age, const string& surname, const string& middlename, const string& birthDate)
	: name(name), age(age), surname(surname), middlename(middlename), birthDate(birthDate) {
}
Person::Person(const Person& other)
	: name(other.name), age(other.age), surname(other.surname), middlename(other.middlename), birthDate(other.birthDate) {
}
Person::~Person()
{
	cout << "Person's " << name << " destructor" << endl;
}

string Person::getName() const {
	return name;
}
int Person::getAge() const {
	return age;
}
string  Person::getSurname()const {
	return surname;
}
string Person::getMiddlename() const {
	return middlename;
}
string Person::getBirthDate() const {
	return birthDate;
}
