#pragma once
#include"Order.h"
#include <string>

class ExecutionOrder : private Order {
private:
    string executor;

public:
    // Конструктор за замовчуванням
    ExecutionOrder();

    // Конструктор з параметрами
    ExecutionOrder(const string& status, const vector<Publication*>& publications, bool isPaid, Reader* reader, int orderID, double totalPrice ,const string& executor);

    // Метод для виконання замовлення
    void executeOrder();

    // Метод для скасування замовлення
    void cancelOrder();

    // Отримання інформації про виконавця
    string getExecutor() const;

    // Виклик методів базового класу для демонстрації роботи з різними класами
    double getOrderTotalPrice(); // Використовує метод базового класу
};

