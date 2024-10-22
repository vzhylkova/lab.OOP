#include "Administrator.h"
#include "Reader.h"
#include "Order.h"
#include "Rating.h"
#include <iostream>

void Administrator::addPublication(const Publication& publication, std::vector<Publication>& publications) {
    publications.push_back(publication);
    std::cout << "Публікація \"" << publication.getTitle() << "\" додана." << std::endl;
}

void Administrator::addRatingToPublication(Publication& publication, const Rating& rating) {
    publication.addRating(rating);
    cout << "Рецензія додана до публікації \"" << publication.getTitle() << "\"." << endl;
}

void Administrator::blacklistReader(Reader& reader, std::vector<Reader>& blacklistedReaders) {
    blacklistedReaders.push_back(reader);
    std::cout << "Читача \"" << reader.getName() << "\" додано до чорного списку." << std::endl;
}

void Administrator::giveDiscount(Reader& reader, double discount) {
    reader.setDiscount(discount);
    std::cout << "Читачеві \"" << reader.getName() << "\" надано знижку: " << discount * 100 << "%" << std::endl;
}

void Administrator::checkPendingOrders(const std::vector<Order>& orders, std::vector<Reader>& blacklistedReaders) {
    for (const auto& order : orders) {
        if (!order.isOrderPaid()) {
            Reader* reader = order.getReader();
            reader->blacklist();  // Додаємо читача до чорного списку
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
//                std::cout << "Читач \"" << order.getReader()->getName()
//                    << "\" має оплатити замовлення протягом "
//                    << (daysLimit - daysPassed) << " днів.\n";
//            }
//        }
//    }
//}
//
//void Administrator::notifySubscriptionExpiry(const std::vector<Reader>& readers, int daysBeforeExpiry) {
//    for (const auto& reader : readers) {
//        if (reader.getSubscriptionDaysLeft() <= daysBeforeExpiry) {
//            std::cout << "Читачу \"" << reader.getName()
//                << "\" потрібно оновити підписку. Залишилось днів: "
//                << reader.getSubscriptionDaysLeft() << ".\n";
//        }
//    }
//}

void Administrator::viewPublications(const std::vector<Publication>& publications) {
    std::cout << "Список публікацій:" << std::endl;
    for (const auto& publication : publications) {
        std::cout << "- Назва: " << publication.getTitle()
            << ", Автор: " << publication.getAuthor()
            << ", Ціна: " << publication.getPrice() << std::endl;
    }
}

void Administrator::viewReaders(const std::vector<Reader>& readers) {
    std::cout << "Список читачів:" << std::endl;
    for (const auto& reader : readers) {
        std::cout << "- Ім'я: " << reader.getName()
            << ", Баланс: " << reader.getBalance()
            << ", Днів підписки залишилось: " << reader.getSubscriptionDaysLeft() << std::endl;
    }
}
