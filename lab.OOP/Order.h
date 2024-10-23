#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Reader.h"
#include "Publication.h"

using namespace std;
class Reader;
class Publication;
class Order {
private:

    Reader* reader; // Читач, який створив замовлення
    vector<Publication*> publications; // Список видань, які замовив читач
    int orderID;
    string status;
    double totalPrice;
    bool isPaid;

public:
    static int totalOrders;
    Order();
    Order(const string& status, const vector<Publication*>& publications, bool isPaid,Reader* reader,int orderID,double totalPrice);

    vector<Publication*> getPublications() const; // Отримання списку видань
    int getOrderID() const;// Отримання ідентифікатора замовлення
    string getStatus() const;
    static int getTotalOrders(); // Статичний метод для отримання загальної кількості замовлень
    Reader* getReader() const; // Отримання читача, який створив замовлення

    // Метод для зміни статусу замовлення
    void setStatus(const string& newStatus);

    void addPublication(Publication* publication);// Додає видання до замовлення
    //void calculateTotalPrice(); // Підраховує загальну вартість замовлення
    double getTotalPrice() const;// Отримання загальної вартості

    void payOrder(); // Оплата замовлення
    bool isOrderPaid() const; // Отримання статусу оплати

    ~Order();
};


