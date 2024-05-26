#include <iostream>
#include <string>
#include <map>


void print_map(std::map<std::string, int> &m) {
    for(auto it : m) {
        std::cout << it.first << " " << it.second;
        std::cout << std::endl;
    }
}

void plus_one(std::map<std::string, int> &m) {
    for(auto &it : m) {
        it.second++;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    std::map<std::string, int> m{{"Иванов", 99}, {"Петров", 430}, {"Семенов", 70}, 
                                {"Котов", 540}, {"Белых", 230}, {"Черных", 350}};

    print_map(m);
    plus_one(m); std::cout << std::endl;
    print_map(m);

    return 0;
}

/*
Создайте отображение map<string, int> и занесите в него пары занести в него информацию о 6 объектах: 
("Иванов", 99), ("Петров", 430), ("Семенов", 70), ("Котов", 540), ("Белых", 230), ("Черных", 350). 
Выведите содержимое отображения на экран. Увеличьте значение каждой пары на единицу и снова распечатайте отображение.
*/