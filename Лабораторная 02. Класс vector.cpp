
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Функция для инициализации векторов со случайными значениями
void initializeRandom(vector<string>& names, vector<int>& scores, int size) {
    // Здесь можно использовать словарь реалистичных имен для генерации случайных имен
    // Но для простоты, просто будем генерировать имена вида "Студент N", где N - порядковый номер
    for (int i = 1; i <= size; i++) {
        names.push_back("Студент " + to_string(i));
        scores.push_back(rand() % 101); // Генерация случайных оценок от 0 до 100
    }
}

// Функция для вывода содержимого вектора с использованием Range-based for-loop
void printVector(const vector<string>& names, const vector<int>& scores) {
    cout << "Имена и оценки студентов:" << endl;
    for (const auto& name : names) {
        cout << name << ": ";
    }
    cout << endl;
    for (const auto& score : scores) {
        cout << score << " ";
    }
    cout << endl;
}

// Функция для вычисления среднего значения оценок
double calculateAverage(const vector<int>& scores) {
    int sum = 0;
    for (const auto& score : scores) {
        sum += score;
    }
    return static_cast<double>(sum) / scores.size();
}

// Функция для вычисления медианы оценок
double calculateMedian(vector<int>& scores) {
    sort(scores.begin(), scores.end()); // Сортировка вектора оценок
    if (scores.size() % 2 == 0) {
        int index1 = scores.size() / 2 - 1;
        int index2 = scores.size() / 2;
        return (scores[index1] + scores[index2]) / 2.0;
    } else {
        int index = scores.size() / 2;
        return scores[index];
    }
}

// Функция для вычисления моды оценок
vector<string> calculateMode(const vector<string>& names, const vector<int>& scores) {
    unordered_map<int, int> frequency; // Частота каждой оценки
    int maxFrequency = 0;
    for (const auto& score : scores) {
        frequency[score]++;
        maxFrequency = max(maxFrequency, frequency[score]);
    }
    vector<string> modeNames;
    for (const auto& score : scores) {
        if (frequency[score] == maxFrequency) {
            modeNames.push_back(names[score]);
        }
    }
    return modeNames;
}

int main() {
    vector<string> names;
    vector<int> scores;

    int choice;
    cout << "Выберите вариант инициализации векторов:" << endl;
    cout << "1. Демонстрационный анализ на дефолтных входных значениях" << endl;
    cout << "2. Анализ на случайных входных значениях" << endl;
    cout << "3. Анализ на входных значениях от пользователя" << endl;
    cin >> choice;

    if (choice == 1) {
        // Демонстрационный анализ на дефолтных входных значениях
        names = { "Студент 1", "Студент 2", "Студент 3", "Студент 4", "Студент 5", "Студент 6", "Студент 7", "Студент 8", "Студент 9", "Студент 10" };
        scores = { 90, 85, 92, 88, 95, 90, 92, 85, 88, 92 };
    } else if (choice == 2) {
        // Анализ на случайных входных значениях
        int size;
        cout << "Введите желаемый размер выборки: ";
        cin >> size;
        initializeRandom(names, scores, size);
    } else if (choice == 3) {
        // Анализ на входных значениях от пользователя
        int size;
        cout << "Введите количество студентов: ";
        cin >> size;
        cout << "Введите имена студентов и их оценки:" << endl;
        for (int i = 0; i < size; i++) {
            string name;
            int score;
            cout << "Студент " << i + 1 << ": ";
            cin >> name >> score;
            names.push_back(name);
            scores.push_back(score);
        }
    }

    printVector(names, scores);

    double average = calculateAverage(scores);
    cout << "Средняя оценка: " << average << endl;

    double median = calculateMedian(scores);
    cout << "Медиана оценок: " << median << endl;

    vector<string> modeNam

PulseGPT - AI Assistant, [17.12.2023 21:44]
es = calculateMode(names, scores);
    cout << "Мода оценок: ";
    for (const auto& name : modeNames) {
        cout << name << " ";
    }
    cout << endl;

    return 0;
}
```

Программа предлагает пользователю выбрать вариант инициализации векторов: 
демонстрационный анализ на дефолтных значениях, анализ на случайных значениях или анализ на входных значениях от пользователя. 
Затем, она выводит содержимое векторов, среднее значение оценок, медиану оценок и моду оценок.