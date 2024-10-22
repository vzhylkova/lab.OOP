#include "Reader.h"
#include "Publication.h"
#include "Rating.h"
#include "Order.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// ����������� ��� ���������
Reader::Reader() 
    : name("Unknown"), readerNumber(0), subscriptionDaysLeft(0), balance(0.0), discount(0.0), isBlacklisted(false), discountRate(0.0) {
    totalReaders++;  
}
// ����������� � �����������
Reader::Reader(string name, int readerNumber, int subscriptionDaysLeft, double balance)
    : name(name), readerNumber(readerNumber), subscriptionDaysLeft(subscriptionDaysLeft), balance(balance), discount(0.0), isBlacklisted(false), discountRate(0.0) {
    totalReaders++;
}
// ����������� ���������
Reader::Reader(const Reader& other)
    : name(other.name), readerNumber(other.readerNumber), subscriptionDaysLeft(other.subscriptionDaysLeft), balance(other.balance), discount(other.discount), isBlacklisted(other.isBlacklisted), discountRate(other.discountRate) {
    totalReaders++;  
}

//������ ��� ��������� ���������� ������
string Reader::getName() const {
    return name;
}
double Reader::getBalance() const {
    return balance;
}
int Reader::getSubscriptionDaysLeft() const {
    return subscriptionDaysLeft;
}
int Reader::getReaderNumber() const {
    return readerNumber;
}
double Reader::getDiscount() const {
    return discount;
}

void Reader::setBalance(double newBalance) {
    balance = newBalance; }
void Reader::setDiscount(double newDiscount) {
    discount = newDiscount;
}

//����� ��� ��������� ������ �� �������
void Reader::addBalance(double amount) {
    balance += amount;
}

//������������ ������ ��� ������ ������
void Reader::payForSubscription(double amount) {
    if (balance >= amount) {
        balance -= amount;
        subscriptionDaysLeft += 30;
    }
    else
    {
        cout << "�� ������� ������ �� �������" << endl;
    }
}
void Reader::payForSubscription(double amount, double discount) {
    double discountedAmount = amount * (1 - discount / 100);
    if (balance >= discountedAmount) {
        balance -= discountedAmount;
        subscriptionDaysLeft += 30;
    }
    else
    {
        cout << "�� ������� ������ �� �������" << endl;
    }
}

//�����, �� ������ ��'��� ����� �� ��������
bool Reader::compareBalance(const Reader& otherReader) const {
    return this->balance > otherReader.balance;
}
void Reader::addRatingToPublication(Publication& publication, int score, const string& feedback) {
    Rating rating(score, feedback);
    publication.addRating(rating);
    cout << "����� \"" << name << "\" ����� ������� �� ��������� \"" << publication.getTitle() << "\"." << endl;
}
//����� ��� ���������� ���������� �� �������
void Reader::placeOrder(Publication* publication) {
    Order newOrder(this); // ��������� ���� ����������
    newOrder.addPublication(publication); // ������ �������
    orders.push_back(newOrder); // ������ ���������� �� ������
}
void Reader::blacklist() {
    isBlacklisted = true;
    std::cout << "����� \"" << name << "\" ������� �� ������� ������.\n";
}

bool Reader::isReaderBlacklisted() const {
    return isBlacklisted;
}
////����� ��� ���������� ���������� �� �������
//void Reader::placeOrder(Publication& publication) {
//    if (balance >= publication.getPrice()) {
//        balance -= publication.getPrice();
//        subscriptionDaysLeft += publication.getSubscriptionPeriod();
//        cout << name << " ������ ��������� �� " << publication.getTitle() << "." << endl;
//    }
//    else {
//        cout << name << " �� �� ��������� ����� ��� ������� �� " << publication.getTitle() << "." << endl;
//    }
//}
//void Reader::writeToFile(const string& filename) const {
//    ofstream outFile(filename, ios::app); // Open file in append mode
//    if (outFile) {
//        outFile << name << "\n"
//            << readerNumber << "\n"
//            << subscriptionDaysLeft << "\n"
//            /*<< blacklisted << "\n"*/
//            << balance << "\n";
//        outFile.close();
//    }
//    else {
//        cerr << "Error opening file for writing." << endl;
//    }
//}

void Reader::writeAllToFile(const vector<Reader>& readers, const string& filename) {
    ofstream outFile(filename, ios::trunc);
    if (outFile) {
        for (const auto& reader : readers) {
            outFile << reader.getName() << "\n"
                << reader.readerNumber << "\n"
                << reader.subscriptionDaysLeft << "\n"
                << reader.balance << "\n";
        }
    }
    else {
        cerr << "Error opening file for writing." << endl;
    }
}
vector<Reader> Reader::readAllFromFile(const string& filename) {
    vector<Reader> readers;
    ifstream inFile(filename);
    if (inFile) {
        while (true) {
            string name;
            int readerNumber;
            int subscriptionDaysLeft;
            double balance;

            if (!getline(inFile, name)) break; // ������� ��'�
            inFile >> readerNumber >> subscriptionDaysLeft >> balance;
            inFile.ignore(); // �������� ������ ������ ����� ���� ���������� double

            readers.emplace_back(name, readerNumber, subscriptionDaysLeft, balance);
        }
        inFile.close();
    }
    else {
        cerr << "������� �������� ����� ��� �������." << endl;
    }
    return readers;
}

//int* Reader::generateAndSortRandomNumbers(int n) {
//    int* randomNumbers = new int[n];  // �������� �������� ���'�� ��� ������ ����� �����
//
//    srand(time(0));
//
//    for (int i = 0; i < n; ++i) {
//        randomNumbers[i] = rand() % 100;
//    }
//    sort(randomNumbers, randomNumbers + n);
//    cout << "³����������� �����: ";
//    for (int i = 0; i < n; ++i) {
//        cout << randomNumbers[i] << " ";
//    }
//    cout << endl;
//
//    return randomNumbers;
//}

int Reader::totalReaders = 0;
// ��������� ����� ��� ��������� �������� ������� �������
int Reader::getTotalReaders() {
    return totalReaders;
}
// ����������
Reader::~Reader() {
    cout << "�������� ��'���� " << name << endl;
}