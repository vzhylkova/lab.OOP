#include "Order.h"
#include "Order.h"
#include "Reader.h"

int Order::totalOrders = 0;

Order::Order()
    : status("Pending"), isPaid(false), reader(nullptr), orderID(0), totalPrice(0.0) {}

Order::Order(const string& status, const vector<Publication*>& publications, bool isPaid,Reader* reader,int orderID,double totalPrice) 
    : status(status), publications(publications), isPaid(isPaid), reader(reader) ,orderID(orderID),totalPrice(totalPrice){
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

string Order::getStatus() const {
    return status;
}

void Order::setStatus(const string& newStatus) {
    status = newStatus;
}

Order::~Order() {
        cout << "Order's destructor" << endl;
    
}