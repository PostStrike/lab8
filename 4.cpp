#include <iostream>
#include <vector>
#include <stdlib.h>
#include <iomanip>

template<class T>
void print_vector(std::vector<T> v) {
    for(int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

template<class T>
T sum(std::vector<T> v) {
    T s = 0;
    for(int i = 0; i < v.size(); ++i) {
        s += v[i];
    }
    return s;
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    std::vector<long double> v(6);
    for(int i = 0; i < 6; ++i) {
        double a  = rand() % 200 - 100;
        int d = rand() % 101;

        a = a + static_cast<double>(d) / 100;
        v[i] = a;
    }       

    print_vector(v);    
    std::cout << sum(v) << std::endl;

    v.erase(v.begin() + 2);
    print_vector(v);

    return 0;
}

/*
Создать вектор из 6-ти вещественных случайных чисел от (−100 до 100). Распечатать. Посчитать сумму всех элементов массива. 
Удалить из вектора элемент с индексом 2 и снова распечатать вектор. Переделать программу: печатать вектор с помощью функции.
*/