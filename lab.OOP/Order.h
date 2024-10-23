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
    string status;
    double totalPrice;
    bool isPaid;

public:
    static int totalOrders;
    Order();
    Order(const string& status, const vector<Publication*>& publications, bool isPaid,Reader* reader,int orderID,double totalPrice);

    vector<Publication*> getPublications() const; // ��������� ������ ������
    int getOrderID() const;// ��������� �������������� ����������
    string getStatus() const;
    static int getTotalOrders(); // ��������� ����� ��� ��������� �������� ������� ���������
    Reader* getReader() const; // ��������� ������, ���� ������� ����������

    // ����� ��� ���� ������� ����������
    void setStatus(const string& newStatus);

    void addPublication(Publication* publication);// ���� ������� �� ����������
    //void calculateTotalPrice(); // ϳ������� �������� ������� ����������
    double getTotalPrice() const;// ��������� �������� �������

    void payOrder(); // ������ ����������
    bool isOrderPaid() const; // ��������� ������� ������

    ~Order();
};


