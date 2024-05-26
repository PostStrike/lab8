#include <iostream>
#include <string>
#include <fstream>

std::string get_text(std::string& s) {
    std::string res = "";

    for(int i = 0; i < s.size() - 3; i++) {
        if(s[i] == '*' && s[i + 1] == '*' && s[i + 2] == '*') {
            for(int j = i + 3; j < s.size(); ++j) {
                res += s[j];
            }
            return res;
        }
    }

    return res;
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::ifstream fin("in.txt");
    std::ofstream fout("out.txt");

    std::string s; 
    while(std::getline(fin, s)) {
        if(get_text(s).size() > 0) {
            fout << get_text(s);
        }
    }

    fin.close();
    fout.close();

    return 0;
}

/*
Дан текстовый файл. Найдите в исходном файле строки, в которых есть три звездочки и текст после них. 
Запишите в другой файл текст после звездочек.
*/