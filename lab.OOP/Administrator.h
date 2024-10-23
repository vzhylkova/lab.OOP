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

    // ��������� ���� ���������
    void addPublication(const Publication& publication, std::vector<Publication>& publications);

    void addRatingToPublication(Publication& publication, const Rating& rating);
   
    void blacklistReader(Reader& reader, std::vector<Reader>& blacklistedReaders); // ��������� ������ �� ������� ������

    void giveDiscount(Reader& reader, double discount);// ������� ������ �������

    // �������� ����������� ��������� �� ��������� �� ������� ������
    void checkPendingOrders(const std::vector<Order>& orders, std::vector<Reader>& blacklistedReaders);

    // �������� ��� ���������
    void viewPublications(const std::vector<Publication>& publications);

    // �������� ��� �������
    void viewReaders(const std::vector<Reader>& readers);

    // ���������� ����������
    //// ��������� ��� ���������� ������ ������ ����������
    //void notifyPendingOrders(const std::vector<Order>& orders, int daysLimit);
    //// ���������� ���������� ��� ��������� ������ �������
    //void notifySubscriptionExpiry(const std::vector<Reader>& readers, int daysBeforeExpiry);
};



