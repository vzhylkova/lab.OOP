#include "ExecutionOrder.h"

ExecutionOrder::ExecutionOrder() : Order(), executor("Unknown") {}

// Parameterized constructor
ExecutionOrder::ExecutionOrder(const string& status, const vector<Publication*>& publications, bool isPaid, Reader* reader, int orderID, double totalPrice, const string& executor)
    : Order(status, publications, isPaid, reader, orderID, totalPrice), executor(executor) {}


void ExecutionOrder::executeOrder() {
    if (getStatus() == "Pending") {
        setStatus("Completed");
        cout << "���������� #" << getOrderID() << " ��������. ������: " << getStatus() << endl;
    }
    else {
        cout << "���������� #" << getOrderID() << " �� ���� ���� ��������. ������: " << getStatus() << endl;
    }
}

void ExecutionOrder::cancelOrder() {
    if (getStatus() == "Pending") {
        setStatus("Cancelled");
        cout << "���������� #" << getOrderID() << " ���������. ������: " << getStatus() << endl;
    }
    else {
        cout << "���������� #" << getOrderID() << " �� ����� ���������. ������: " << getStatus() << endl;
    }
}

string ExecutionOrder::getExecutor() const {
    return executor;
}

double ExecutionOrder::getOrderTotalPrice() {
    return getTotalPrice(); // ������������ ������ �������� �����
}