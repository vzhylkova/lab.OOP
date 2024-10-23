#pragma once
#include <vector>
#include <ctime>
#include "Person.h"
#include "user.h"
#include "Publication.h"
#include "Reader.h"
#include "Order.h"

using namespace personNamespace;

class Administrator : public Person, User{
public:

    Administrator(const string& name,
        int age,
        const string& surname,
        const string& middlename,
        const string& birthDate,
        const string& email);

    ~Administrator();

    // Додавання нової публікації
    void addPublication(const Publication& publication, std::vector<Publication>& publications);

    void addRatingToPublication(Publication& publication, const Rating& rating);
   
    void blacklistReader(Reader& reader, std::vector<Reader>& blacklistedReaders); // Додавання читача до чорного списку

    void giveDiscount(Reader& reader, double discount);// Надання знижки читачеві

    // Перевірка непогашених замовлень та додавання до чорного списку
    void checkPendingOrders(const std::vector<Order>& orders, std::vector<Reader>& blacklistedReaders);

    // Перегляд всіх публікацій
    void viewPublications(const std::vector<Publication>& publications);

    // Перегляд всіх читачів
    void viewReaders(const std::vector<Reader>& readers);

    // Надсилання нагадувань
    //// Оповіщення про наближення терміну оплати замовлення
    //void notifyPendingOrders(const std::vector<Order>& orders, int daysLimit);
    //// Надсилання нагадувань про закінчення терміну підписки
    //void notifySubscriptionExpiry(const std::vector<Reader>& readers, int daysBeforeExpiry);
};



