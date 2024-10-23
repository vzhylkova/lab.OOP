#pragma once
#include <string>

using namespace std;

class User
{
public:
    User();
    User(const std::string& email);
    User(const User& other);
    ~User();

    string email;

protected:
    string getEmail() const;
};


