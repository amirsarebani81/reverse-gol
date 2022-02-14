#include <vector>
#include <cstddef>
#include <iostream>
#include "gol.hpp"

std::vector<char> get_initial_table(size_t hight, size_t width, size_t level, const std::vector<char> &final_table)
{
    for (size_t k = 0; k < (1 << final_table.size()); k++)
    {
        std::vector<char> initial_table(final_table.size(), EMPTY);

        for (size_t i = 0; i < final_table.size(); i++)
            if (k & (1 << i))
                initial_table[i] = MUSHROOM;

        if (check_tables_conversion(hight, width, level, initial_table, final_table))
            return initial_table;
    }

    return std::vector<char>(0);
}

bool check_tables_conversion(size_t hight, size_t width, size_t level, const std::vector<char> &initial_table, const std::vector<char> &final_table)
{
    std::vector<char> current_table = initial_table;

    for (size_t i = 0; i < level; i++)
        current_table = get_next_table(hight, width, current_table);

    return final_table == current_table;
}

std::vector<int> get_adjacents(size_t hight, size_t width, const std::vector<char> &table)
{
    std::vector<int> adjacents(table.size(), 0);

    for (size_t i = 0; i < hight; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            if (table[i * width + j] == MUSHROOM)
            {
                for (int i_diff = -1; i_diff <= 1; i_diff++)
                {
                    for (int j_diff = -1; j_diff <= 1; j_diff++)
                    {
                        if (i_diff == 0 && j_diff == 0)
                            continue;

                        size_t new_i = (i + i_diff + hight) % hight;
                        size_t new_j = (j + j_diff + width) % width;
                        adjacents[new_i * width + new_j]++;
                    }
                }
            }
        }
    }

    return adjacents;
}

std::vector<char> get_next_table(size_t hight, size_t width, const std::vector<char> &table)
{
    std::vector<char> next_table = table;
    std::vector<int> adjacents = get_adjacents(hight, width, table);

    for (size_t i = 0; i < hight; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            if (table[i * width + j] == MUSHROOM && !(adjacents[i * width + j] == 2 || adjacents[i * width + j] == 3))
                next_table[i * width + j] = EMPTY;
            if (table[i * width + j] == EMPTY && adjacents[i * width + j] == 3)
                next_table[i * width + j] = MUSHROOM;
        }
    }
    return next_table;
}

void print_table(size_t hight, size_t width, const std::vector<char> &table)
{
    if (table.size() == 0)
    {
        std::cout << "impossible\n";
        return;
    }

    for (size_t i = 0; i < table.size(); i++)
    {
        std::cout << table[i];
        if (i % width == width - 1)
            std::cout << std::endl;
    }
}