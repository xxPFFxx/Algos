#include <iostream>

using namespace std;
long long n, x[100005], y[100005], sum=0;

int cmp(const void * x1, const void * x2) { return (*(long*)x1 - *(long*)x2); } // Компаратор для qsort, сортирующий по возрастанию

int main()
{
    cin >> n;
    for (long i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    // Сортируем координаты, чтобы затем можно было искать дорогу между соседними по координатам точками
    qsort(x, n, sizeof(long long), cmp);
    qsort(y, n, sizeof(long long), cmp);

    for (long i=1; i<n; i++)
    {
        sum += (x[i] - x[i - 1] + y[i] - y[i - 1]) * i * (n - i) * 2; // Складываем разницу по x и y, затем умножаем на число дорог, которые используют этот участок
    }
    cout << sum / (n*(n - 1)); // Делим на n(n-1), т.к. это общее число путей между городами
    return 0;
}

