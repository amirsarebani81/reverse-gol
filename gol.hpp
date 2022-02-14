#ifndef GOL_HPP
#define GOL_HPP

#include <cstddef>
#include <vector>

#define EMPTY '.'
#define MUSHROOM '*'

std::vector<char> get_initial_table(size_t, size_t, size_t, const std::vector<char> &);

bool check_tables_conversion(size_t, size_t, size_t, const std::vector<char> &, const std::vector<char> &);

std::vector<int> get_adjacents(size_t, size_t, const std::vector<char> &);

std::vector<char> get_next_table(size_t, size_t, const std::vector<char> &);

void print_table(size_t, size_t, const std::vector<char> &);

#endif