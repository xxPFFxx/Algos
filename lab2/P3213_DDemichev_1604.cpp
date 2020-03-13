#include <iostream>
using namespace std;
// Класс для хранения информации о знаках (их текущее количество и индекс для вывода)
class sign {
public:
    int count;
    int index;
};


int main() {
    int k;
    cin >> k;

    int minValue = INT_MAX;
    int maxValue = INT_MIN;
    int minIndex = -1;
    int maxIndex = -1;
    sign * signs = new sign[k];

    // Находим знак и наибольшим и наименьшим количеством, запоминаем их индексы и количество
    for (int i = 0; i < k; i++) {
        cin >> signs[i].count;
        signs[i].index = i + 1;
        if (signs[i].count >= maxValue) {
            maxValue = signs[i].count;
            maxIndex = i;
        }
        if (signs[i].count < minValue) {
            minValue = signs[i].count;
            minIndex = i;
        }
    }
    // Продолжаем то же самое, выводя каждый раз пару знаков, пока либо их не останется, либо останутся знаки одного типа
    while (minIndex != maxIndex && minValue != INT_MAX) {
        printf("%i %i ", signs[maxIndex].index, signs[minIndex].index);
        signs[maxIndex].count--;
        signs[minIndex].count--;
        maxValue = INT_MIN;
        minValue = INT_MAX;
        for (int i = 0; i < k; i++) {
            if (signs[i].count != 0 && signs[i].count >= maxValue) {
                maxValue = signs[i].count;
                maxIndex = i;
            }
            if (signs[i].count != 0 && signs[i].count < minValue) {
                minValue = signs[i].count;
                minIndex = i;
            }
        }
    }
    // Если остались знаки одного типа, нужно их вывести в конце
    for (int i = 0; i < maxValue; i++) {
        printf("%i ", signs[maxIndex].index);
    }
    return 0;
}