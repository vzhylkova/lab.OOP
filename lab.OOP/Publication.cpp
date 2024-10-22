#include "Publication.h"
#include "Rating.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int Publication::totalPublications = 0;
double Publication::maxDiscount = 0.2;
double Publication::minPrice = 5.0;

// ����������� ��� ���������
Publication::Publication()
    : author("Unknown"), title("Unknown"), price(0.0), subscriptionPeriod(0), genre(new string("Genre")) {
    totalPublications++;
}

// ����������� � ����������� �� ����������� �������� � ��������
Publication::Publication(const string& author,const string& title, double price, int subscriptionPeriod, string* genre)
    : author(author),title(title), price(price), subscriptionPeriod(subscriptionPeriod), genre(new string(*genre)){
    totalPublications++;
}

Publication::Publication(string* title, double price, int subscriptionPeriod, string* genre)
    : title(*title), price(price), subscriptionPeriod(subscriptionPeriod), genre(new string(*genre)){
    totalPublications++;
}

// ����������� ���������
Publication::Publication(const Publication& other)
    : author(other.author), title(other.title), price(other.price), subscriptionPeriod(other.subscriptionPeriod), ratings(other.ratings), feedback(other.feedback), genre(new string(*other.genre)) {
    totalPublications++;
}

string Publication::getAuthor() const {
    return author;
}
string Publication::getTitle() const {
    return title;
}
double Publication::getPrice() const {
    return price;
}
string Publication::getGenre() const {
    return *genre;
}
int Publication::getSubscriptionPeriod() const {
    return subscriptionPeriod;
}

// ��������� �������� �� ��������� ����� ���� Rating
void Publication::addRating(const Rating& rating) {
    Rating::addRating(ratings, rating);
    cout << "������� ��� ��������� \"" << title << "\" ������!" << endl;
}

// ����� ��� ��������� ��� ��������
//vector<Rating>& Publication::getRatings() {
//    return ratings;
//}
vector<Rating> Publication::getRatings() const {
    return ratings;
}
////��������� ���������� ��������
//double Publication::getAverageRating() const {
//    if (ratings.empty()) return 0.0;
//    double sum = 0.0;
//    for (int rating : ratings) {
//        sum += rating;
//    }
//    return sum / ratings.size();
//}
//
////������ ��� ������
//void Publication::addFeedback(string feedback) {
//    this->feedback = feedback;
//}
//void Publication::addFeedback(string feedback, int rating) {
//    this->feedback = feedback;
//    this->addRating(rating);
//}

//����� �� ������� ��� ����� 
Publication Publication::getCopy() const {
    return *this;
}

//void Publication::writeAllToFile(const vector<Publication>& publications, const string& filename) {
//    ofstream outFile(filename, ios::trunc); // ³�������� ���� � ����� ����������
//    if (outFile) {
//        for (const auto& publication : publications) {
//            outFile << publication.getTitle() << "\n"
//                << publication.getPrice() << "\n"
//                << publication.getSubscriptionPeriod() << "\n"
//                << publication.getGenre();
//        }
//    }
//    else {
//        cerr << "Error opening file for writing." << endl;
//    }
//}
//
//vector<Publication> Publication::readAllFromFile(const string& filename) {
//    vector<Publication> publications;
//    ifstream inFile(filename);
//
//    if (inFile) {
//        while (true) {
//            string title;
//            double price;
//            int subscriptionPeriod;
//            string genre;
//
//            if (!getline(inFile, title)) break; // ������� �����
//            inFile >> price >> subscriptionPeriod;
//            inFile.ignore(); // �������� ������ ������ ����� ���� ����������
//            getline(inFile, genre);
//
//            publications.emplace_back(title, price, subscriptionPeriod, new string(genre));
//        }
//        inFile.close();
//    }
//    else {
//        cerr << "Error opening file for reading." << endl;
//    }
//    return publications;
//}

int Publication::getTotalPublications(){
    return totalPublications;
}

// ��������� ���������� ������ ��� ��������� ������ �������
//��������� ������� ���� ��������� �����, ��� ����������� �ᒺ�� �����. ������� ����� � ��������, �������� � ����.
Publication Publication::createPublication(string* title, double price, int subscriptionPeriod, string* genre) {
    return Publication(title, price, subscriptionPeriod, genre); // ���������� ������ ������������
}



// ����������
Publication::~Publication() {
    cout << "�������� ��'���� " << title << endl;
}
