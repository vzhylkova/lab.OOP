#include "Reader.h"
#include "Publication.h"
#include "Administrator.h"
#include "Order.h"
#include"ExecutionOrder.h"
#include "Rating.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

// Функція для обчислення та виведення загальної вартості замовлення
void calculateTotalPrice(const Order& order)
{
    double totalPrice = 0;
    for (const auto& publication : order.getPublications()) {
        totalPrice += publication->getPrice();
    }
    cout << "Total Price of the Order: " << totalPrice << endl;
}

// Перевантажена функція, що використовує адресу об'єкта
void calculateTotalPrice(const Order* order) {
    double totalPrice = 0.0;
    for (const auto& publication : order->getPublications()) {
        totalPrice += publication->getPrice();
    }
    cout << "Total Price of the Order (using pointer): " << totalPrice << endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Ukrainian");

    Administrator admin("Ivan", 30, "Ivanov", "Ivanovich", "01.01.1993", "admin@example.com");

    vector<Reader> readersVector{};

    // Додавання читачів з використанням конструктора
    readersVector.push_back(Reader("John", 25, "Doe", "Smith", "01.01.1999", "john@example.com", 1, 30, 100.0, 0.1, false));
    readersVector.push_back(Reader("Jane", 28, "Smith", "Doe", "02.02.1996", "jane@example.com", 2, 15, 50.0, 0.05, false));
    readersVector.push_back(Reader("Alice", 22, "Johnson", "Alice", "03.03.2002", "alice@example.com", 3, 20, 75.5, 0.07, false));
    readersVector.push_back(Reader("Bob", 30, "Brown", "Robert", "04.04.1994", "bob@example.com", 4, 10, 25.0, 0.0, false));
    readersVector.push_back(Reader("Charlie", 27, "Black", "Charles", "05.05.1997", "charlie@example.com", 5, 5, 60.0, 0.03, true));
        
    // Жанри для публікацій
    string genre1 = "Programming";
    string genre2 = "Algorithms";
    string genre3 = "Design";
    string genre4 = "AI";
    string genre5 = "Web";
    
    vector<Publication> publicationsVector{};

    // Додавання публікацій з використанням конструктора та статичного методу createPublication
    publicationsVector.push_back(Publication("Bjarne Stroustrup", "C++ Programming", 29.99, 30, &genre1));
    publicationsVector.push_back(Publication("Thomas Cormen", "Data Structures and Algorithms", 39.99, 45, &genre2));
    publicationsVector.push_back(Publication());  // Використання конструктора за замовчуванням
    publicationsVector.push_back(Publication("Stuart Russell", "Artificial Intelligence", 59.99, 90, &genre3));
    publicationsVector.push_back(Publication::createPublication("Ethan Brown", "Web Development", 19.99, 30, &genre4));
    
    admin.viewPublications(publicationsVector);// Адміністратор переглядає всі публікації
    admin.viewReaders(readersVector);// Адміністратор переглядає всіх читачів 

    // Оформлення замовлення
    vector<Publication*> orderPublications = { &publicationsVector[0], &publicationsVector[1] }; // Замовлення на дві публікації
    readersVector[0].placeOrder(orderPublications[0]); // Додаємо першу публікацію до замовлення
    readersVector[0].placeOrder(orderPublications[1]); // Додаємо другу публікацію до замовлення
    // Створіть замовлення
    Order order("Pending", orderPublications, false, &readersVector[0], 1, 0.0);

    calculateTotalPrice(order);

    // Створіть замовлення
    ExecutionOrder execOrder("Pending", orderPublications, false, &readersVector[0], 1, 0.0, "Alice Johnson");

    // Виконання замовлення
    execOrder.executeOrder();

    // Читач сплачує за підписку
    readersVector[0].payForSubscription(10.0);

    // Додавання рейтингу
    Rating rating(5, "Great book!");
    admin.addRatingToPublication(publicationsVector[0], rating);
    readersVector[0].addRatingToPublication(publicationsVector[1], 5, "Fantastic read!");

    // Перегляд відгуків
    vector<Rating> ratings = publicationsVector[0].getRatings();
    Rating::printAllFeedbacks(ratings);

       
    

   

//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    setlocale(LC_ALL, "Ukrainian");
//
//    // Використання динамічного масиву для читачів
//    vector<Reader> readersVector{};
//
//    readersVector.push_back(Reader("John Doe", 1, 30, 100.0));
//    readersVector.push_back(Reader("Jane Smith", 2, 15, 50.0));
//    readersVector.push_back(Reader("Alice Johnson", 3, 20, 75.5));
//    readersVector.push_back(Reader("Bob Brown", 4, 10, 25.0));
//    readersVector.push_back(Reader("Charlie Black", 5, 5, 60.0));
//
//    // Жанри для публікацій
//    string genre1 = "Programming";
//    string genre2 = "Algorithms";
//    string genre3 = "Design";
//    string genre4 = "AI";
//    string genre5 = "Web";
//
//    // //Створення масиву публікацій
//    //Publication publications[5] = {
//    //   Publication("Bjarne Stroustrup", "C++ Programming", 29.99, 30, &genre1), // Конструктор з параметрами
//    //   Publication("Thomas Cormen", "Data Structures and Algorithms", 39.99, 45, &genre2),// Конструктор з параметрами
//    //   Publication(),//конструктор без параметрів
//    //   Publication("Stuart Russell", "Artificial Intelligence", 59.99, 90, &genre4),// Конструктор з параметрами
//    //   Publication("Ethan Brown", "Web Development", 19.99, 30, &genre5)// Конструктор з параметрами
//
//    //};
//    vector<Publication> publicationsVector;
//    publicationsVector.push_back(Publication("Bjarne Stroustrup", "C++ Programming", 29.99, 30, &genre1));
//    publicationsVector.push_back(Publication("Thomas Cormen", "Data Structures and Algorithms", 39.99, 45, &genre2));
//    publicationsVector.push_back(Publication());
//    publicationsVector.push_back(Publication("Stuart Russell", "Artificial Intelligence", 59.99, 90, &genre4));
//    publicationsVector.push_back(Publication::createPublication("Ethan Brown", "Web Development", 19.99, 30, &genre5));
//    
//   
//    // Створення адміністратора
//    Administrator admin;
//
//   /////* vector<Reader> readersVector(readers, readers + 5);*/
//   //// /*vector<Reader> readersVector;
//   //// for (int i = 0; i < 5; ++i) {
//   ////     readersVector.push_back(*readers[i]);
//   //// }*/
//    // Запис усіх читачів у файл
//    Reader::writeAllToFile(readersVector, "readers.txt");
//
//    //// Запис усіх публікацій у файл
//    //Publication::writeAllToFile(vector<Publication>(publications, publications + 5), "publications.txt");
//   Publication::writeAllToFile(publicationsVector, "publications.txt");
//
//    // Читання всіх читачів з файлу
//    vector<Reader> allReaders = Reader::readAllFromFile("readers.txt");
//    cout << "Читачі:\n";
//    for (const auto& reader : allReaders) {
//        cout << "Name: " << reader.getName() << endl;
//        cout << "Reader Number: " << reader.getReaderNumber() << endl;
//        cout << "Days Left: " << reader.getSubscriptionDaysLeft() << endl;
//        cout << "Balance: " << reader.getBalance() << endl;
//        cout << endl;
//    }
//    //vector<Publication> allPublications = Publication::readAllFromFile("publications.txt");
//    //
//    //// Виведення інформації про публікації
//    //cout << "Публікації:\n";
//    //for (const auto& publication : allPublications) {
//    //    cout << "Title: " << publication.getTitle() << endl;
//    //    cout << "Price: " << publication.getPrice() << endl;
//    //    cout << "Subscription Period: " << publication.getSubscriptionPeriod() << endl;
//    //   /* cout << "Average Rating: " << publication.getAverageRating() << endl;*/
//    //    cout << endl;
//    //}
//
//    // Використання покажчика на екземпляр класу Reader
//    cout << "Демонстрація використання покажчика на екземпляр класу Reader:\n";
//    Reader* readerPtr = &readersVector[0];  // Створення покажчика на об'єкт
//
//    cout << readerPtr->getName() << " має баланс: " << readerPtr->getBalance() << endl;
//    readerPtr->addBalance(75);
//    cout << "" << readerPtr->getBalance() << endl;
//
//    cout << readersVector[1].getName() << " з номером " << readersVector[1].getReaderNumber() << " має до закінчення підписки " << readersVector[1].getSubscriptionDaysLeft() << " днів." << endl;
//    readersVector[1].payForSubscription(50.0);
//    cout << "Заплативши за підписку баланс читача " << readersVector[1].getBalance() << " та кількість днів до закінчення підписки " << readersVector[1].getSubscriptionDaysLeft() << endl;
//    cout << readersVector[4].getName() << " з номером " << readersVector[4].getReaderNumber() << " має до закінчення підписки " << readersVector[4].getSubscriptionDaysLeft() << " днів, та баланс " << readersVector[4].getBalance() << endl;
//    readersVector[4].payForSubscription(50, 10);
//    cout << "Заплативши за підписку баланс читача " << readersVector[4].getBalance() << " та кількість днів до закінчення підписки " << readersVector[4].getSubscriptionDaysLeft() << endl;
//
//    if (readerPtr->compareBalance(readersVector[2])) {
//        cout << readerPtr->getName() << " має більший баланс, ніж " << readersVector[2].getName() << endl;
//    }
//    else {
//        cout << readersVector[2].getName() << " має більший або рівний баланс, ніж " << readerPtr->getName() << endl;
//    }
//    // Створюємо замовлення для читача
//    Order order(&readersVector[0]);  // Наприклад, замовлення для John Doe
//    order.addPublication(&publicationsVector[0]); // Додаємо першу публікацію
//    order.addPublication(&publicationsVector[1]); // Додаємо другу публікацію
//
//    Rating rating1(5, "Відмінна публікація про C++!");
//    Rating rating2(4, "Гарна книга про алгоритми.");
//
//    admin.addRatingToPublication(publicationsVector[0], rating1);
//    admin.addRatingToPublication(publicationsVector[1], rating2);
//
//    // Обчислюємо загальну вартість замовлення
//    calculateTotalPrice(order);
//
//    // Виводимо інформацію про замовлення та публікації
//    cout << "Інформація про замовлення:" << endl;
//    for (const auto& pub : order.getPublications()) {
//        cout << "Назва: " << pub->getTitle() << ", Ціна: " << pub->getPrice() << endl;
//    }


    //readers[3]->placeOrder(publications[1]);
    //readerPtr->placeOrder(publications[2]);
    //
    //readers[4]->generateAndSortRandomNumbers(5);
    //
    //// Демонстрація всіх методів для Publication
    //cout << "\nДемонстрація методів класу Publication:\n";
    //cout << "Назва публікації: " << publications[0].getTitle() << endl;
    //cout << "Ціна підписки: " << publications[0].getPrice() << endl;
    //cout << "Термін підписки: " << publications[0].getSubscriptionPeriod() << endl;
    //// Додавання рейтингу та відгуків
    //publications[1].addRating(5);
    //publications[0].addRating(4);
    //publications[0].addFeedback("Дуже корисна книга!", 5);
    //cout << "Середній рейтинг публікації: " << publications[0].getAverageRating() << endl;
    //
    //Publication copyOfPublication = publications[0].getCopy();
    //cout << "Копія публікації: " << copyOfPublication.getTitle() << " з ціною: " << copyOfPublication.getPrice() << endl;
    //
    // Очищення пам'яті для динамічних об'єктів
   
    /*for (int i = 0; i < 5; ++i) {
        delete readers[i];
    }*/
    return 0;
}