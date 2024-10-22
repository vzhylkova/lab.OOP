#include "Order.h"
#include "Order.h"
#include "Reader.h"

int Order::totalOrders = 0;

// ����������� �� �������������
Order::Order() : reader(nullptr), totalPrice(0), isPaid(false) {
    orderID = ++totalOrders;
}
// ����������� � �����������
Order::Order(Reader* reader) : reader(reader), totalPrice(0), isPaid(false) {
    orderID = ++totalOrders;
}

// ���� ������� �� ����������
void Order::addPublication(Publication* publication) {
    publications.push_back(publication);
    totalPrice += publication->getPrice(); // ��������� �������� ������� ����������
}


// ������ ����������
void Order::payOrder() {
    double totalPrice = getTotalPrice(); // �������� �������� ���� ����������
    if (reader->getBalance() >= totalPrice) {
        // ³������ ���� �������������
        double newBalance = reader->getBalance() - totalPrice;
        reader->setBalance(newBalance); // ��������� ������ ������
        isPaid = true;
    }
    else {
        cout << "����������� ����� �� ������� ��� ������ ����������." << endl;
    }
}

// ��������� �������� �������
double Order::getTotalPrice() const {
    return totalPrice;
}

// ��������� ������� ������
bool Order::isOrderPaid() const {
    return isPaid;
}

// ��������� ������ ������
vector<Publication*> Order::getPublications() const {
    return publications;
}

// ��������� �������������� ����������
int Order::getOrderID() const {
    return orderID;
}

// ��������� ����� ��� ��������� �������� ������� ���������
int Order::getTotalOrders() {
    return totalOrders;
}

Reader* Order::getReader() const {
    return reader;
}
