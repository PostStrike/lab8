#include <iostream>
#include <string>

int main() {
    setlocale(LC_ALL, "Russian");

    std::string s1; std::cout << "Введите текст: "; std::cin >> s1; 

    std::string s2 = "";
    int i = 0;
    while(s1[i] != '{') i++;
    i++;
    while(s1[i] != '}') {
        s2 += s1[i];
        i++;
    }  

    std::cout << s2 << std::endl;

    return 0;
}

/*
Пользователь вводит некоторый текст, содержащий пару фигурных скобок. 
Создать новый текст, включив в него текст заключенный в фигурные скобки (не использовать find).
*/