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
    
    Reader* reader; // �����, ���� ������� ����������
    vector<Publication*> publications; // ������ ������, �� ������� �����
    int orderID;
    double totalPrice;
    bool isPaid;

public:
    static int totalOrders;

    // ����������� �� �������������
    Order();
    // ����������� � �����������
    Order(Reader* reader);

    vector<Publication*> getPublications() const; // ��������� ������ ������
    int getOrderID() const;// ��������� �������������� ����������
    
    static int getTotalOrders(); // ��������� ����� ��� ��������� �������� ������� ���������
    Reader* getReader() const; // ��������� ������, ���� ������� ����������

    void addPublication(Publication* publication);// ���� ������� �� ����������
    //void calculateTotalPrice(); // ϳ������� �������� ������� ����������
    double getTotalPrice() const;// ��������� �������� �������

    void payOrder(); // ������ ����������
    bool isOrderPaid() const; // ��������� ������� ������
};


