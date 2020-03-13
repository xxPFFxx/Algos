using namespace std;
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
// Класс для хранения точек (id - номер для вывода, x и y - координаты, angle - угол)
class Point {
public:
    int id;
    int x,y;
    double angle;
    // Метод для преобразования координат к новой системе координат
    void new_coordinates(int cx, int cy) {
        this->x-=cx;
        this->y-=cy;
        angle = atan2(y,x);
    }
};
// Компаратор для функции sort, сортирующий точки по углу
bool comparer(Point a, Point b) {
    return (a.angle > b.angle);
}

int main() {
    int n;
    cin >> n;
    vector<Point> points;
    int x,y;
    cin >> x >> y;
    points.push_back({0,x,y,0});
    int mi = 0, mx = x, my = y;
    // Ищем точку с минимальным y, запоминаем ее координаты и индекс
    for(int i=1;i<n;i++) {
        cin >> x >> y;
        points.push_back({i,x,y,0});
        if(y < my) {
            mi = i,
            mx = x,
            my = y;
        }
    }
    points.erase(points.begin()+mi); // Удаляем опорную точку, т.к. она является основанием системы координат
    for(auto & point : points) point.new_coordinates(mx,my); // Обновляем координаты точек

    sort(points.begin(),points.end(),comparer); // Отсортировали оставшиеся точки по углу
    cout << mi+1 << " " << points.at(points.size()/2).id+1; // Вывели опорную и среднюю точки
    return 0;
}
