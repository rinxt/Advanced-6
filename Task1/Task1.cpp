#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

int main() {
    system("chcp 1251");
    std::string fileName;

    std::cout << "Введите имя файла в формате <имя файла.txt>: ";
    std::cin >> fileName;
    std::ifstream inputFile(fileName);

    // Проверка открытия файла
    if (!inputFile.is_open()) {
        std::cerr << "Ошибка при открытии файла " << fileName << std::endl;
        return 1;
    }

    std::map<char, int> charFrequency;
    char ch;

    // Чтение символов из файла в map
    while (inputFile.get(ch)) {
        charFrequency[ch]++;
    }

    inputFile.close();

    // Вектор из пар <символ, частота>
    std::vector<std::pair<char, int>> charFrequencyVector(charFrequency.begin(), charFrequency.end());

    // Сортируем вектор
    std::sort(charFrequencyVector.begin(), charFrequencyVector.end(),
        [](const std::pair<char, int>& a, const std::pair<char, int>& b) {
            return a.second > b.second;
        });

    for (const auto& pair : charFrequencyVector) {
        std::cout << "Символ " << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
