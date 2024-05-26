#include <iostream>
#include <map>

void print_map(std::map<std::string, int> &m) {
    for(auto it : m) {
        std::cout << it.first << " " << it.second;
        std::cout << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    std::map<std::string, int> m1{{"яблоки", 100}, {"груши", 13}, {"арбузы", 20}, {"картофель", 15}, {"алыча", 22}};
    std::map<std::string, int> m2{{"яблоки", 150}, {"груши", 18}, {"ананасы", 45}, {"апельсины", 30}, {"киви", 35}};

    std::map<std::string, int> m;
    for(auto it : m1) {
        m[it.first] = std::max(m1[it.first], m2[it.first]);
    }
    for(auto it : m2) {
        m[it.first] = std::max(m1[it.first], m2[it.first]);
    }

    print_map(m);

    return 0;
}

/*
Необходимо объединить два прайс-листа (задаются в виде отображений) с тем условием, 
что если наименование товара присутствует в обоих прайсах, то в итоговый прайс помещается тот, чья цена выше.

m1 = {'яблоки': 100, 'груши': 13, 'арбузы': 20, 'картофель': 15, 'алыча': 22}
m2 = {'яблоки': 150,'груши': 18,'ананасы': 45, 'апельсины': 30, 'киви': 35}

Распечатать содержимое отображений в консоли, используя функцию.
*/