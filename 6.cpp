#include <iostream>
#include <list>
#include <stdlib.h>
#include <iomanip>

template<class T>
void print_list(std::list<T> l) {
    for (auto it : l){
        std::cout << it << " ";
    }
    std::cout << std::endl;
}

template<class T>
T sum(std::list<T> l) {
    T s = 0;
    for(auto it : l) {
        s += it;
    }
    return s;
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    std::list<long double> l;
    for(int i = 0; i < 6; ++i) {
        double a  = rand() % 200 - 100;
        int d = rand() % 1001;

        a = a + static_cast<double>(d) / 1000;
        l.push_back(a);
    }       

    print_list(l);    
    std::cout << sum(l) << std::endl;

    auto it = l.begin(); it++; it++;
    l.erase(it);
    
    print_list(l);

    return 0;
}

/*
Создать контейнер из 6-ти вещественных случайных чисел от (−100 до 100). Распечатать. Посчитать сумму всех элементов массива. 
Удалить из контейнера элемент с индексом 2 и снова распечатать контейнер. Переделать программу: печатать контейнер с помощью функции.
*/