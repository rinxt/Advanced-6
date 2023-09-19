#include <iostream>
#include <set>

int main()
{
    std::set<int> numbers;

    int numbersCount;
    std::cin >> numbersCount;

    for (int i = 0; i < numbersCount; i++) {
        int num;
        std::cin >> num;
        numbers.insert(num);
    }

    for (auto it = numbers.rbegin(); it != numbers.rend(); ++it) {
        std::cout << *it << " ";
    }
}

