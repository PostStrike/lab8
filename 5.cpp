#include <iostream>
#include <vector>

class Time {
private:
    int h;
    int m;
    int s;
public:
    Time(){
        h = 0; m = 0; s = 0;
    };

    Time(int h, int m, int s) {
        this->s = 60 * 60 * h + 60 * m + s;

        this->h = this->s / 60 / 60;
        this->s -= this->h * 60 * 60;
        this->m = this->s / 60;
        this->s -= this->m * 60;
    }

    bool operator==(Time& t) {
        return h * 60 * 60 + m * 60 + s == t.h * 60 * 60 + t.m * 60 + t.s;
    }

    bool operator<(Time& t) {
        return h * 60 * 60 + m * 60 + s < t.h * 60 * 60 + t.m * 60 + t.s;
    }

    void print() {
        printf("%d:%d:%d\n", h, m, s);
    }
};

void print_vector(std::vector<Time>& v) {
    for(int i = 0; i < v.size(); ++i) {
        v[i].print();
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    std::vector<std::vector<int>> arr{{1, 2, 63}, {4, 57, 19}, {7, 32, 20}, {5, 13, 23}, {10, 19, 45}, {19, 9, 59}};

    std::vector<Time> timers;
    for(int i = 0; i < arr.size(); ++i) {
        Time t(arr[i][0], arr[i][1], arr[i][2]);
        timers.push_back(t);
    }

    std::vector<Time> res;
    for(Time t : timers) {
        Time bottom;
        Time top(5, 0, 0);

        if(t < top || t == top) {
            res.push_back(t);
        }
    }

    print_vector(res);

    return 0;
}

/*
Создайте класс с именем Time, содержащий три закрытых поля типа int, предназначенные для хранения часов, минут и секунд (подсказка: не забудьте для класса Time определить операторы < и ==). 
Один из конструкторов класса должен инициализировать поля нулевыми значениями, а другой конструктор — заданным набором значений.

Создайте метод класса, который будет выводить значения полей на экран в формате 11:59:59.

Создать массив объектов типа Time с помощью контейнера vector в main() и сразу занести в него информацию о шести датах: 
(1, 2, 63), (14, 57, 19), (7, 32, 20), (5, 13, 23), (10, 19, 45), (19, 9, 59). 
Вывести массив на экран таким образом, чтобы каждая дата выводились в отдельной строке. 
Создайте новый вектор, в который запишите даты первого вектора, которые относятся к ночи (с 0 до 5 часов).Выведите на экран второй вектор. 
Напишите функцию вывода массива на экран.
*/