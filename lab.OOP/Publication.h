#pragma once
#include "Rating.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Publication {
private:
	const string author;  // Константне поле для імені автора
	string title;
	double price;
	int subscriptionPeriod;
	vector<Rating> ratings;
	string feedback;
	string* genre;  // Поле типу посилання

public:
	static int totalPublications;
	static double maxDiscount;
	static double minPrice;

	// Конструктор без параметрів.Простий конструктор 
	Publication();
	// Конструктор з параметрами та одночасно конструктор з ініціалізацією констант і посилань .Явний конструктор
	Publication(const string& author,const string& title, double price, int subscriptionPeriod, string* genre);
	// Конструктор з параметрами
	Publication(string* title, double price, int subscriptionPeriod, string* genre);
	// Конструктор копіювання
	Publication(const Publication& other);

	string getAuthor() const;
	string getTitle() const;
	double getPrice() const;
	string getGenre() const;
	int getSubscriptionPeriod() const;
	int getTotalPublications();
	Publication getCopy() const;
	
	// Додавання рейтингу до публікації через клас Rating
	void addRating(const Rating& rating);
	vector<Rating> getRatings() const;

	/*double getAverageRating() const;
	void addFeedback(string feedback);
	void addFeedback(string feedback, int rating);*/
	
	static void writeAllToFile(const vector<Publication>& publications, const string& filename);
	//static vector<Publication> readAllFromFile(const string& filename);
	
	// Функція для створення нового видання
	static Publication createPublication(const string& author,const string& title, double price, int subscriptionPeriod, string* genre);

	~Publication();
};
