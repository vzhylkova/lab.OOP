#include "Order.h"
#include "Order.h"
#include "Reader.h"

int Order::totalOrders = 0;

Order::Order()
    : status("Pending"), isPaid(false), reader(nullptr), orderID(0), totalPrice(0.0) {}

Order::Order(const string& status, const vector<Publication*>& publications, bool isPaid,Reader* reader,int orderID,double totalPrice) 
    : status(status), publications(publications), isPaid(isPaid), reader(reader) ,orderID(orderID),totalPrice(totalPrice){
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

string Order::getStatus() const {
    return status;
}

void Order::setStatus(const string& newStatus) {
    status = newStatus;
}

Order::~Order() {
        cout << "Order's destructor" << endl;
    
}