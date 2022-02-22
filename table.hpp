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
    std::vector<T> v;

public:
    Table();
    Table(const std::size_t, const std::size_t);
    Table(const std::size_t, const std::size_t, T);
    std::size_t get_height() const;
    std::size_t get_width() const;
    T get(const std::size_t, const std::size_t) const;
    void set(const std::size_t, const std::size_t, const T);
    void print() const;
    bool equal(const Table<T> &) const;
    bool empty() const;
};

template <typename T>
Table<T>::Table()
    : height(0), width(0), v(std::vector<T>(0)) {}

template <typename T>
Table<T>::Table(const std::size_t h, const std::size_t w)
    : height(h), width(w), v(std::vector<T>(h * w)) {}

template <typename T>
Table<T>::Table(const std::size_t h, const std::size_t w, T value)
    : height(h), width(w), v(std::vector<T>(h * w, value)) {}

template <typename T>
std::size_t Table<T>::get_height() const { return height; }

template <typename T>
std::size_t Table<T>::get_width() const { return width; }

template <typename T>
T Table<T>::get(const std::size_t i, const std::size_t j) const { return v[i * get_width() + j]; }

template <typename T>
void Table<T>::set(const std::size_t i, const std::size_t j, const T value) { v[i * get_width() + j] = value; }

template <typename T>
void Table<T>::print() const
{
    for (std::size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i];
        if (i % get_width() == get_width() - 1)
            std::cout << std::endl;
    }
}

template <typename T>
bool Table<T>::equal(const Table<T> &table) const
{
    if (get_height() != table.get_height() || get_width() != table.get_width())
        return false;
    for (std::size_t i = 0; i < v.size(); i++)
        if (v[i] != table.v[i])
            return false;
    return true;
}

template <typename T>
bool Table<T>::empty() const { return !get_height() || !get_width(); }

#endif