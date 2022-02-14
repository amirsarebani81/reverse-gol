#include <iostream>
#include <cstddef>
#include <vector>
#include "gol.hpp"

int main()
{
    size_t hight, width, level;
    std::cin >> hight >> width >> level;

    std::vector<char> table(hight * width);
    for (size_t i = 0; i < hight * width; i++)
        std::cin >> table[i];

    std::vector<char> initial_table = get_initial_table(hight, width, level, table);
    print_table(hight, width, initial_table);
}