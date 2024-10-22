#include "Order.h"
#include "Order.h"
#include "Reader.h"

int Order::totalOrders = 0;

// Конструктор за замовчуванням
Order::Order() : reader(nullptr), totalPrice(0), isPaid(false) {
    orderID = ++totalOrders;
}
// Конструктор з параметрами
Order::Order(Reader* reader) : reader(reader), totalPrice(0), isPaid(false) {
    orderID = ++totalOrders;
}

// Додає видання до замовлення
void Order::addPublication(Publication* publication) {
    publications.push_back(publication);
    totalPrice += publication->getPrice(); // Оновлюємо загальну вартість замовлення
}


// Оплата замовлення
void Order::payOrder() {
    double totalPrice = getTotalPrice(); // Отримуємо загальну ціну замовлення
    if (reader->getBalance() >= totalPrice) {
        // Віднімемо суму безпосередньо
        double newBalance = reader->getBalance() - totalPrice;
        reader->setBalance(newBalance); // Оновлюємо баланс читача
        isPaid = true;
    }
    else {
        cout << "Недостатньо коштів на рахунку для оплати замовлення." << endl;
    }
}

// Отримання загальної вартості
double Order::getTotalPrice() const {
    return totalPrice;
}

// Отримання статусу оплати
bool Order::isOrderPaid() const {
    return isPaid;
}

// Отримання списку видань
vector<Publication*> Order::getPublications() const {
    return publications;
}

// Отримання ідентифікатора замовлення
int Order::getOrderID() const {
    return orderID;
}

// Статичний метод для отримання загальної кількості замовлень
int Order::getTotalOrders() {
    return totalOrders;
}

Reader* Order::getReader() const {
    return reader;
}
