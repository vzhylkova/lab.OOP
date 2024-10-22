#include "Reader.h"
#include "Publication.h"
#include "Administrator.h"
#include "Order.h"
#include "Rating.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

// ������� ��� ���������� �� ��������� �������� ������� ����������
void calculateTotalPrice(const Order& order)
{
    double totalPrice = 0;
    for (const auto& publication : order.getPublications()) {
        totalPrice += publication->getPrice();
    }
    cout << "Total Price of the Order: " << totalPrice << endl;
}

// ������������� �������, �� ����������� ������ ��'����
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

    // ������������ ���������� ������ ��� �������
    vector<Reader> readersVector{};

    readersVector.push_back(Reader("John Doe", 1, 30, 100.0));
    readersVector.push_back(Reader("Jane Smith", 2, 15, 50.0));
    readersVector.push_back(Reader("Alice Johnson", 3, 20, 75.5));
    readersVector.push_back(Reader("Bob Brown", 4, 10, 25.0));
    readersVector.push_back(Reader("Charlie Black", 5, 5, 60.0));

    // ����� ��� ���������
    string genre1 = "Programming";
    string genre2 = "Algorithms";
    string genre3 = "Design";
    string genre4 = "AI";
    string genre5 = "Web";

     //��������� ������ ���������
    Publication publications[5] = {
       Publication("Bjarne Stroustrup", "C++ Programming", 29.99, 30, &genre1), // ����������� � �����������
       Publication("Thomas Cormen", "Data Structures and Algorithms", 39.99, 45, &genre2),// ����������� � �����������
       Publication(),//����������� ��� ���������
       Publication("Stuart Russell", "Artificial Intelligence", 59.99, 90, &genre4),// ����������� � �����������
       Publication("Ethan Brown", "Web Development", 19.99, 30, &genre5)// ����������� � �����������
    };
    //vector<Publication> publicationsVector;
    //publicationsVector.emplace_back("Bjarne Stroustrup", "C++ Programming", 29.99, 30, &genre1);
    //publicationsVector.emplace_back("Thomas Cormen", "Data Structures and Algorithms", 39.99, 45, &genre2);
    //publicationsVector.emplace_back();  // ����������� ����������� ��� ���������
    //publicationsVector.emplace_back("Stuart Russell", "Artificial Intelligence", 59.99, 90, &genre4);
    //publicationsVector.emplace_back("Ethan Brown", "Web Development", 19.99, 30, &genre5);

    // ��������� ������������
    Administrator admin;

   /////* vector<Reader> readersVector(readers, readers + 5);*/
   //// /*vector<Reader> readersVector;
   //// for (int i = 0; i < 5; ++i) {
   ////     readersVector.push_back(*readers[i]);
   //// }*/
    // ����� ��� ������� � ����
    Reader::writeAllToFile(readersVector, "readers.txt");

    //// ����� ��� ��������� � ����
    //Publication::writeAllToFile(vector<Publication>(publications, publications + 5), "publications.txt");
 /*   Publication::writeAllToFile(publicationsVector, "publications.txt");*/

    // ������� ��� ������� � �����
    vector<Reader> allReaders = Reader::readAllFromFile("readers.txt");
    cout << "������:\n";
    for (const auto& reader : allReaders) {
        cout << "Name: " << reader.getName() << endl;
        cout << "Reader Number: " << reader.getReaderNumber() << endl;
        cout << "Days Left: " << reader.getSubscriptionDaysLeft() << endl;
        cout << "Balance: " << reader.getBalance() << endl;
        cout << endl;
    }
    //vector<Publication> allPublications = Publication::readAllFromFile("publications.txt");
    //
    //// ��������� ���������� ��� ���������
    //cout << "���������:\n";
    //for (const auto& publication : allPublications) {
    //    cout << "Title: " << publication.getTitle() << endl;
    //    cout << "Price: " << publication.getPrice() << endl;
    //    cout << "Subscription Period: " << publication.getSubscriptionPeriod() << endl;
    //   /* cout << "Average Rating: " << publication.getAverageRating() << endl;*/
    //    cout << endl;
    //}

    // ������������ ��������� �� ��������� ����� Reader
    cout << "������������ ������������ ��������� �� ��������� ����� Reader:\n";
    Reader* readerPtr = &readersVector[0];  // ��������� ��������� �� ��'���

    cout << readerPtr->getName() << " �� ������: " << readerPtr->getBalance() << endl;
    readerPtr->addBalance(75);
    cout << "" << readerPtr->getBalance() << endl;

    cout << readersVector[1].getName() << " � ������� " << readersVector[1].getReaderNumber() << " �� �� ��������� ������� " << readersVector[1].getSubscriptionDaysLeft() << " ���." << endl;
    readersVector[1].payForSubscription(50.0);
    cout << "���������� �� ������� ������ ������ " << readersVector[1].getBalance() << " �� ������� ��� �� ��������� ������� " << readersVector[1].getSubscriptionDaysLeft() << endl;
    cout << readersVector[4].getName() << " � ������� " << readersVector[4].getReaderNumber() << " �� �� ��������� ������� " << readersVector[4].getSubscriptionDaysLeft() << " ���, �� ������ " << readersVector[4].getBalance() << endl;
    readersVector[4].payForSubscription(50, 10);
    cout << "���������� �� ������� ������ ������ " << readersVector[4].getBalance() << " �� ������� ��� �� ��������� ������� " << readersVector[4].getSubscriptionDaysLeft() << endl;

    if (readerPtr->compareBalance(readersVector[2])) {
        cout << readerPtr->getName() << " �� ������ ������, �� " << readersVector[2].getName() << endl;
    }
    else {
        cout << readersVector[2].getName() << " �� ������ ��� ����� ������, �� " << readerPtr->getName() << endl;
    }
    // ��������� ���������� ��� ������
    Order order(&readersVector[0]);  // ���������, ���������� ��� John Doe
    order.addPublication(&publications[0]); // ������ ����� ���������
    order.addPublication(&publications[1]); // ������ ����� ���������

    Rating rating1(5, "³����� ��������� ��� C++!");
    Rating rating2(4, "����� ����� ��� ���������.");

    admin.addRatingToPublication(publications[0], rating1);
    admin.addRatingToPublication(publications[1], rating2);

    // ���������� �������� ������� ����������
    calculateTotalPrice(order);

    // �������� ���������� ��� ���������� �� ���������
    cout << "���������� ��� ����������:" << endl;
    for (const auto& pub : order.getPublications()) {
        cout << "�����: " << pub->getTitle() << ", ֳ��: " << pub->getPrice() << endl;
    }


    //readers[3]->placeOrder(publications[1]);
    //readerPtr->placeOrder(publications[2]);
    //
    //readers[4]->generateAndSortRandomNumbers(5);
    //
    //// ������������ ��� ������ ��� Publication
    //cout << "\n������������ ������ ����� Publication:\n";
    //cout << "����� ���������: " << publications[0].getTitle() << endl;
    //cout << "ֳ�� �������: " << publications[0].getPrice() << endl;
    //cout << "����� �������: " << publications[0].getSubscriptionPeriod() << endl;
    //// ��������� �������� �� ������
    //publications[1].addRating(5);
    //publications[0].addRating(4);
    //publications[0].addFeedback("���� ������� �����!", 5);
    //cout << "������� ������� ���������: " << publications[0].getAverageRating() << endl;
    //
    //Publication copyOfPublication = publications[0].getCopy();
    //cout << "���� ���������: " << copyOfPublication.getTitle() << " � �����: " << copyOfPublication.getPrice() << endl;
    //
    // �������� ���'�� ��� ��������� ��'����
   
    /*for (int i = 0; i < 5; ++i) {
        delete readers[i];
    }*/
    return 0;
}