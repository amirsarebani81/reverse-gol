#include <iostream>
#include <cstddef>
#include "gol.hpp"
#include "table.hpp"

int main()
{
    std::size_t height, width, level;
    std::cin >> height >> width >> level;

    Table<char> table(height, width);
    for (std::size_t i = 0; i < height; i++)
        for (std::size_t j = 0; j < width; j++)
            std::cin >> table[i][j];

    Gol gol(table, level);
    Table<char> result = gol.solve();
    if (result.empty())
        std::cout << "impossible" << std::endl;
    else
        std::cout << result;
}