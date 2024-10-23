#pragma once
#include "Person.h"
#include "user.h"
#include "Publication.h"
#include "Order.h"
#include "Rating.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
using namespace personNamespace;

class Order;
//class Publication;
class Reader : public Person, User
{
private:
	/*string name;*/
	int readerNumber;
	int subscriptionDaysLeft;
	double balance;
	bool isBlacklisted;
	double discount;
	vector<Order> orders;
public:
	static int totalReaders; // �������� ������� �������
	//double discountRate; // �������� ������ ��� �������
	//double minimumBalance; // ̳�������� ������ ��� �������
	
	// ����������� ��� ���������
	Reader();

	// ����������� � �����������
	Reader(const string& name,
		int age,
		const string& surname,
		const string& middlename,
		const string& birthDate,
		const string& email,
		int readerNumber,
		int subscriptionDaysLeft,
		double balance,
		double discount,
		bool isBlacklisted);

	// ����������� ���������
	Reader(const Reader& other);

	//string getName() const;
	double getBalance() const;
	int getSubscriptionDaysLeft() const;
	int getReaderNumber() const;
	static int getTotalReaders();// ��������� ����� ��� ��������� �������� ������� �������
	double getDiscount() const;

	void setBalance(double newBalance);
	void setDiscount(double discount);

	void addBalance(double amount);//��������� ������ �� �������
	void payForSubscription(double amount);//����� ��� ������ ������
	void payForSubscription(double amount, double discount);//����� ��� ������ ������

	void addRatingToPublication(Publication& publication, int score, const string& feedback);// ����� ��� ��������� �������� �� ���������

	// ��������� �� ������� ������
	void blacklist();
	bool isReaderBlacklisted() const;
	
	void placeOrder(Publication* publication);//���������� ���������� �� ������� (��'���� �� ��'������)
	//static void writeAllToFile(const vector<Reader>& readers, const string& filename);//����� � ����
	//static vector<Reader> readAllFromFile(const string& filename);//���������� � �����

	//int* generateAndSortRandomNumbers(int n);
	bool compareBalance(const Reader& otherReader) const;//����� �� ������ ��'��� ����� �� ��������
	

	~Reader();
};

