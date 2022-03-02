#ifndef TABLE_HPP
#define TABLE_HPP

#include <vector>
#include <iostream>
#include <cstddef>

template <typename T>
class Table
{
private:
    std::size_t height, width;
    std::vector<T> vec;

public:
    Table()
        : height(0), width(0), vec(std::vector<T>(0)) {}

    Table(const std::size_t h, const std::size_t w)
        : height(h), width(w), vec(std::vector<T>(h * w)) {}

    Table(const std::size_t h, const std::size_t w, T v)
        : height(h), width(w), vec(std::vector<T>(h * w, v)) {}

    std::size_t get_height() const { return height; }

    std::size_t get_width() const { return width; }

    bool empty() const { return !get_height() || !get_width(); }

    typename std::vector<T>::iterator operator[](std::size_t index) { return vec.begin() + index * get_width(); }

    typename std::vector<T>::const_iterator operator[](std::size_t index) const { return vec.cbegin() + index * get_width(); }

    bool operator==(const Table<T> &table) const { return get_height() == table.get_height() && get_width() == table.get_width() && vec == table.vec; }

    bool operator!=(const Table<T> &table) const { return !(this == table); }
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Table<T> &table)
{
    for (std::size_t i = 0; i < table.get_height(); i++)
    {
        for (std::size_t j = 0; j < table.get_width(); j++)
            os << table[i][j];
        os << std::endl;
    }
    return os;
}

#endif