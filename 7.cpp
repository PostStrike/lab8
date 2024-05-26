#include <iostream>
#include <list>
#include <string>

class Inventory {
private:
    std::string item;
    double cost;
    int on_hand;

public:
    Inventory() {
        item = "";
        cost = 0;
        on_hand = 0;
    };

    Inventory(std::string item, double cost, int on_hand) {
        this->item = item;
        this->cost = cost;
        this->on_hand = on_hand;
    };

    bool operator==(int t) {
        return on_hand == t;
    }

    bool operator==(Inventory& t) {
        return cost * on_hand == t.cost * t.on_hand;
    }

    bool operator<(Inventory& t) {
        return cost * on_hand < t.cost * t.on_hand;
    }

    void print() {
        std::cout << item << " - " << cost << " - " << on_hand << std::endl;
    }
};

template<class T>
void print_list(std::list<T> l) {
    for (auto it : l){
        it.print();
    }
}

struct Temp {
    std::string s;
    int first;
    int second;
};

int main() {
    setlocale(LC_ALL, "Russian");
    
    Temp arr[6] = {Temp{"Отверка", 99, 0}, Temp{"Молоток", 430, 10}, Temp{"Гайки", 70, 100}, Temp{"Профиль", 540, 0}, 
                                                                            Temp{"Уголок", 230, 9}, {"Доска", 350, 17}};

    std::list<Inventory> tools;
    for(int i = 0; i < 6; ++i) {
        Inventory t(arr[i].s, arr[i].first, arr[i].second);
        tools.push_back(t);
    }

    print_list(tools);

    std::list<Inventory> new_tools;
    for(auto it : tools) {
        if(it == 0) {
            new_tools.push_back(it);
        }
    }

    std::cout << std::endl;
    print_list(new_tools);

    return 0;
}


/*
Создать класс Inventory для учета товаров на складе. Класс содержит следующие закрытые компоненты: 
string item – наименование товара, double cost – стоимость, int on_hand – количество 
(подсказка: не забудьте для класса Inventory определить операторы < и ==). 
Один из конструкторов класса должен инициализировать поля нулевыми значениями, а другой конструктор — заданным набором значений.

Создать список объектов типа Inventory с помощью контейнера list в main() и сразу занести в него информацию о шести объектах: 
("Отверка", 99, 0), ("Молоток", 430, 10), ("Гайки", 70, 100), ("Профиль", 540, 0), ("Уголок", 230, 9), ("Доска", 350, 17). 
Вывести список на экран таким образом, чтобы каждый товар выводился в отдельной строке:

Отверка - 99 - 0
Молоток - 430 - 10
Гайки - 70 - 100
Профиль - 540 - 0
Уголок - 230 - 9
Доска - 350 - 17

Создайте новый список, в который объекты первого списка, у которых количество равно нулю. Выведите на экран второй список. 
Напишите функцию вывода списка на экран.
*/