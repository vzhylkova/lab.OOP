#pragma once
#include <string>

using namespace std;

namespace personNamespace
{
    class Person
    {
    protected:

        int age;
        string name;
        string surname;
        string middlename;
        

        Person();
        Person(const string& name, int age, const string& surname, const string& middlename, const string& birthDate);
        Person(const Person& other);
        ~Person();
    public:

        int getAge() const;
        string getName() const;
        string getSurname() const;
        string getMiddlename() const;
        string getBirthDate() const;
    private:
        string birthDate;

    };
}

