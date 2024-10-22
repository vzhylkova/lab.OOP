#include "Rating.h"

// Конструктор з параметрами
Rating::Rating(int score, const string& feedback) : score(score), feedback(feedback) {}

// Метод для отримання рейтингу
int Rating::getScore() const {
    return score;
}

// Метод для отримання відгуку
string Rating::getFeedback() const {
    return feedback;
}

// Статичний метод для обчислення середнього рейтингу
double Rating::calculateAverageRating(const vector<Rating>& ratings) {
    if (ratings.empty()) return 0.0;
    int totalScore = 0;
    for (const auto& rating : ratings) {
        totalScore += rating.getScore();
    }
    return static_cast<double>(totalScore) / ratings.size();
}

// Статичний метод для виведення всіх відгуків
void Rating::printAllFeedbacks(const vector<Rating>& ratings) {
    for (const auto& rating : ratings) {
        cout << "Оцінка: " << rating.getScore() << ", Відгук: " << rating.getFeedback() << endl;
    }
}

// Статичний метод для додавання рейтингу до списку
void Rating::addRating(vector<Rating>& ratings, const Rating& rating) {
    ratings.push_back(rating);
}
