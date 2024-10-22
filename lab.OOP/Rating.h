#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Rating
{
private:
    int score;          // Рейтинг (наприклад, від 1 до 5)
    string feedback;    // Відгук

public:
    // Конструктор з параметрами
    Rating(int score, const string& feedback);

    // Метод для отримання рейтингу
    int getScore() const;

    // Метод для отримання відгуку
    string getFeedback() const;

    // Статичний метод для обчислення середнього рейтингу
    static double calculateAverageRating(const vector<Rating>& ratings);

    // Статичний метод для виведення всіх відгуків
    static void printAllFeedbacks(const vector<Rating>& ratings);

    // Статичний метод для додавання рейтингу до списку
    static void addRating(vector<Rating>& ratings, const Rating& rating);
};



