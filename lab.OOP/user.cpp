#include "user.h"
#include <iostream>
#include <string>

using namespace std;

User::User():email("unknown"){}
User::User(const string& email) : email(email) {}
User::User(const User& other)
	:email(other.email){}


User::~User()
{
	cout << "User's " << email << " destructor" << std::endl;
}

string User::getEmail() const
{
	return email;
}
