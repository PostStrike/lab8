#include <iostream>
#include <string>

int main() {
    setlocale(LC_ALL, "Russian");

    std::string s1; std::cout << "Первое слово: "; std::cin >> s1; 
    std::string s2; std::cout << "Второе слово: "; std::cin >> s2;
    std::string s3; std::cout << "Третье слово: "; std::cin >> s3;

    std::string s = s1 + " " + s2 + " " + s3;
    std::cout << s << std::endl;

    return 0;
}

/*
Пользователь вводит 3 слова в 3-х разных переменных. Образовать новую символьную переменную, хранящую все три слова через пробел.
*/