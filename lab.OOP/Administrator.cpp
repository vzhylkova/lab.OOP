#include "Administrator.h"
#include "Reader.h"
#include "Order.h"
#include "Rating.h"
#include <iostream>

void Administrator::addPublication(const Publication& publication, std::vector<Publication>& publications) {
    publications.push_back(publication);
    std::cout << "��������� \"" << publication.getTitle() << "\" ������." << std::endl;
}

void Administrator::addRatingToPublication(Publication& publication, const Rating& rating) {
    publication.addRating(rating);
    cout << "������� ������ �� ��������� \"" << publication.getTitle() << "\"." << endl;
}

void Administrator::blacklistReader(Reader& reader, std::vector<Reader>& blacklistedReaders) {
    blacklistedReaders.push_back(reader);
    std::cout << "������ \"" << reader.getName() << "\" ������ �� ������� ������." << std::endl;
}

void Administrator::giveDiscount(Reader& reader, double discount) {
    reader.setDiscount(discount);
    std::cout << "������� \"" << reader.getName() << "\" ������ ������: " << discount * 100 << "%" << std::endl;
}

void Administrator::checkPendingOrders(const std::vector<Order>& orders, std::vector<Reader>& blacklistedReaders) {
    for (const auto& order : orders) {
        if (!order.isOrderPaid()) {
            Reader* reader = order.getReader();
            reader->blacklist();  // ������ ������ �� ������� ������
            blacklistedReaders.push_back(*reader);
        }
    }
}


//void Administrator::notifyPendingOrders(const std::vector<Order>& orders, int daysLimit) {
//    std::time_t now = std::time(nullptr);
//    for (const auto& order : orders) {
//        if (!order.isOrderPaid()) {
//            std::time_t creationDate = order.getCreationDate();
//            double secondsPassed = std::difftime(now, creationDate);
//            int daysPassed = secondsPassed / (60 * 60 * 24);
//
//            if (daysPassed >= (daysLimit - 2) && daysPassed <= daysLimit) {
//                std::cout << "����� \"" << order.getReader()->getName()
//                    << "\" �� �������� ���������� �������� "
//                    << (daysLimit - daysPassed) << " ���.\n";
//            }
//        }
//    }
//}
//
//void Administrator::notifySubscriptionExpiry(const std::vector<Reader>& readers, int daysBeforeExpiry) {
//    for (const auto& reader : readers) {
//        if (reader.getSubscriptionDaysLeft() <= daysBeforeExpiry) {
//            std::cout << "������ \"" << reader.getName()
//                << "\" ������� ������� �������. ���������� ���: "
//                << reader.getSubscriptionDaysLeft() << ".\n";
//        }
//    }
//}

void Administrator::viewPublications(const std::vector<Publication>& publications) {
    std::cout << "������ ���������:" << std::endl;
    for (const auto& publication : publications) {
        std::cout << "- �����: " << publication.getTitle()
            << ", �����: " << publication.getAuthor()
            << ", ֳ��: " << publication.getPrice() << std::endl;
    }
}

void Administrator::viewReaders(const std::vector<Reader>& readers) {
    std::cout << "������ �������:" << std::endl;
    for (const auto& reader : readers) {
        std::cout << "- ��'�: " << reader.getName()
            << ", ������: " << reader.getBalance()
            << ", ��� ������� ����������: " << reader.getSubscriptionDaysLeft() << std::endl;
    }
}
