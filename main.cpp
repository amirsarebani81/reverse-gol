#include <iostream>
#include <cstddef>
#include <vector>

#define EMPTY '.'
#define MUSHROOM '*'

std::vector<std::vector<char>> check_all_possibilities(const std::vector<std::vector<char>> &, size_t);
bool check_tables_conversion(const std::vector<std::vector<char>> &, const std::vector<std::vector<char>> &, size_t);
std::vector<std::vector<int>> get_adjacents(const std::vector<std::vector<char>> &);
std::vector<std::vector<char>> get_next_table(const std::vector<std::vector<char>> &);
void print_table(const std::vector<std::vector<char>> &);

int main()
{
    size_t hight, width, level;
    std::cin >> hight >> width >> level;

    std::vector<std::vector<char>> table(hight, std::vector<char>(width));
    for (size_t i = 0; i < hight; i++)
        for (size_t j = 0; j < width; j++)
            std::cin >> table[i][j];

    print_table(check_all_possibilities(table, level));
}

std::vector<std::vector<char>> check_all_possibilities(const std::vector<std::vector<char>> &final_table, size_t level)
{
    size_t hight = final_table.size(), width = final_table[0].size();

    for (size_t k = 0; k < (1 << hight * width); k++)
    {
        std::vector<std::vector<char>> initial_table(hight, std::vector<char>(width, EMPTY));

        for (size_t i = 0; i < hight; i++)
            for (size_t j = 0; j < width; j++)
                if (k & (1 << i * width + j))
                    initial_table[i][j] = MUSHROOM;

        if (check_tables_conversion(initial_table, final_table, level))
            return initial_table;
    }

    return std::vector<std::vector<char>>(0);
}

bool check_tables_conversion(const std::vector<std::vector<char>> &initial_table, const std::vector<std::vector<char>> &final_table, size_t l)
{
    std::vector<std::vector<char>> current_table = initial_table;

    for (size_t i = 0; i < l; i++)
        current_table = get_next_table(current_table);

    return final_table == current_table;
}

std::vector<std::vector<int>> get_adjacents(const std::vector<std::vector<char>> &table)
{
    size_t hight = table.size(), width = table[0].size();
    std::vector<std::vector<int>> adjacents(hight, std::vector<int>(width, 0));

    for (size_t i = 0; i < hight; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            if (table[i][j] == MUSHROOM)
            {
                for (int i_diff = -1; i_diff <= 1; i_diff++)
                {
                    for (int j_diff = -1; j_diff <= 1; j_diff++)
                    {
                        if (i_diff == 0 && j_diff == 0)
                            continue;

                        size_t new_i = (i + i_diff + hight) % hight;
                        size_t new_j = (j + j_diff + width) % width;
                        adjacents[new_i][new_j]++;
                    }
                }
            }
        }
    }

    return adjacents;
}

// todo
// from here
std::vector<std::vector<char>> get_next_table(const std::vector<std::vector<char>> &table)
{
    size_t hight = table.size(), width = table[0].size();

    std::vector<std::vector<char>> next_table = table;
    std::vector<std::vector<int>> adjacents = get_adjacents(table);

    for (size_t i = 0; i < hight; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            if (table[i][j] == MUSHROOM && !(adjacents[i][j] == 2 || adjacents[i][j] == 3))
                next_table[i][j] = EMPTY;
            if (table[i][j] == EMPTY && adjacents[i][j] == 3)
                next_table[i][j] = MUSHROOM;
        }
    }
    return next_table;
}

void print_table(const std::vector<std::vector<char>> &table)
{
    if (table.size() == 0)
    {
        std::cout << "impossible\n";
        return;
    }

    for (std::vector<char> row : table)
    {
        for (char cell : row)
        {
            std::cout << cell;
        }
        std::cout << std::endl;
    }
}