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
    double totalPrice;
    bool isPaid;

public:
    static int totalOrders;

    // Конструктор за замовчуванням
    Order();
    // Конструктор з параметрами
    Order(Reader* reader);

    vector<Publication*> getPublications() const; // Отримання списку видань
    int getOrderID() const;// Отримання ідентифікатора замовлення
    
    static int getTotalOrders(); // Статичний метод для отримання загальної кількості замовлень
    Reader* getReader() const; // Отримання читача, який створив замовлення

    void addPublication(Publication* publication);// Додає видання до замовлення
    //void calculateTotalPrice(); // Підраховує загальну вартість замовлення
    double getTotalPrice() const;// Отримання загальної вартості

    void payOrder(); // Оплата замовлення
    bool isOrderPaid() const; // Отримання статусу оплати
};


