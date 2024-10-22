#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Rating
{
private:
    int score;          // ������� (���������, �� 1 �� 5)
    string feedback;    // ³����

public:
    // ����������� � �����������
    Rating(int score, const string& feedback);

    // ����� ��� ��������� ��������
    int getScore() const;

    // ����� ��� ��������� ������
    string getFeedback() const;

    // ��������� ����� ��� ���������� ���������� ��������
    static double calculateAverageRating(const vector<Rating>& ratings);

    // ��������� ����� ��� ��������� ��� ������
    static void printAllFeedbacks(const vector<Rating>& ratings);

    // ��������� ����� ��� ��������� �������� �� ������
    static void addRating(vector<Rating>& ratings, const Rating& rating);
};



