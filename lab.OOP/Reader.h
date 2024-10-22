#pragma once
#include "Publication.h"
#include "Order.h"
#include "Rating.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Order;
//class Publication;
class Reader
{
private:
	string name;
	int readerNumber;
	int subscriptionDaysLeft;
	double balance;
	bool isBlacklisted;
	double discount;
	vector<Order> orders;
public:
	static int totalReaders; // Загальна кількість читачів
	double discountRate; // Загальна знижка для читачів
	//double minimumBalance; // Мінімальний баланс для підписки

	// Конструктор без параметрів
	Reader();
	// Конструктор з параметрами
	Reader(string name, int readerNumber, int subscriptionDaysLeft, double balance);
	// Конструктор копіювання
	Reader(const Reader& other);

	string getName() const;
	double getBalance() const;
	int getSubscriptionDaysLeft() const;
	int getReaderNumber() const;
	static int getTotalReaders();// Статичний метод для отримання загальної кількості читачів
	double getDiscount() const;

	void setBalance(double newBalance);
	void setDiscount(double discount);

	void addBalance(double amount);//додавання грошей на рахунок
	void payForSubscription(double amount);//метод для сплати заявки
	void payForSubscription(double amount, double discount);//метод для сплати заявки

	void addRatingToPublication(Publication& publication, int score, const string& feedback);// Метод для додавання рейтингу до публікації

	// Додавання до чорного списку
	void blacklist();
	bool isReaderBlacklisted() const;
	
	void placeOrder(Publication* publication);//оформлення замовлення на видання (зв'язок між об'єктами)
	static void writeAllToFile(const vector<Reader>& readers, const string& filename);//запис у файл
	static vector<Reader> readAllFromFile(const string& filename);//зчитуаання з файлу

	//int* generateAndSortRandomNumbers(int n);
	bool compareBalance(const Reader& otherReader) const;//метод що приймає об'єкт класу як параметр
	

	~Reader();
};

