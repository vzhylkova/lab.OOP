#include "Rating.h"

// ����������� � �����������
Rating::Rating(int score, const string& feedback) : score(score), feedback(feedback) {}

// ����� ��� ��������� ��������
int Rating::getScore() const {
    return score;
}

// ����� ��� ��������� ������
string Rating::getFeedback() const {
    return feedback;
}

// ��������� ����� ��� ���������� ���������� ��������
double Rating::calculateAverageRating(const vector<Rating>& ratings) {
    if (ratings.empty()) return 0.0;
    int totalScore = 0;
    for (const auto& rating : ratings) {
        totalScore += rating.getScore();
    }
    return static_cast<double>(totalScore) / ratings.size();
}

// ��������� ����� ��� ��������� ��� ������
void Rating::printAllFeedbacks(const vector<Rating>& ratings) {
    for (const auto& rating : ratings) {
        cout << "������: " << rating.getScore() << ", ³����: " << rating.getFeedback() << endl;
    }
}

// ��������� ����� ��� ��������� �������� �� ������
void Rating::addRating(vector<Rating>& ratings, const Rating& rating) {
    ratings.push_back(rating);
}
