#pragma once
#include"Order.h"
#include <string>

class ExecutionOrder : private Order {
private:
    string executor;

public:
    // ����������� �� �������������
    ExecutionOrder();

    // ����������� � �����������
    ExecutionOrder(const string& status, const vector<Publication*>& publications, bool isPaid, Reader* reader, int orderID, double totalPrice ,const string& executor);

    // ����� ��� ��������� ����������
    void executeOrder();

    // ����� ��� ���������� ����������
    void cancelOrder();

    // ��������� ���������� ��� ���������
    string getExecutor() const;

    // ������ ������ �������� ����� ��� ������������ ������ � ������ �������
    double getOrderTotalPrice(); // ����������� ����� �������� �����
};

