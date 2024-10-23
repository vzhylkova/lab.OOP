#pragma once
#include "Rating.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Publication {
private:
	const string author;  // ���������� ���� ��� ���� ������
	string title;
	double price;
	int subscriptionPeriod;
	vector<Rating> ratings;
	string feedback;
	string* genre;  // ���� ���� ���������

public:
	static int totalPublications;
	static double maxDiscount;
	static double minPrice;

	// ����������� ��� ���������.������� ����������� 
	Publication();
	// ����������� � ����������� �� ��������� ����������� � ������������ �������� � �������� .����� �����������
	Publication(const string& author,const string& title, double price, int subscriptionPeriod, string* genre);
	// ����������� � �����������
	Publication(string* title, double price, int subscriptionPeriod, string* genre);
	// ����������� ���������
	Publication(const Publication& other);

	string getAuthor() const;
	string getTitle() const;
	double getPrice() const;
	string getGenre() const;
	int getSubscriptionPeriod() const;
	int getTotalPublications();
	Publication getCopy() const;
	
	// ��������� �������� �� ��������� ����� ���� Rating
	void addRating(const Rating& rating);
	vector<Rating> getRatings() const;

	/*double getAverageRating() const;
	void addFeedback(string feedback);
	void addFeedback(string feedback, int rating);*/
	
	static void writeAllToFile(const vector<Publication>& publications, const string& filename);
	//static vector<Publication> readAllFromFile(const string& filename);
	
	// ������� ��� ��������� ������ �������
	static Publication createPublication(const string& author,const string& title, double price, int subscriptionPeriod, string* genre);

	~Publication();
};
