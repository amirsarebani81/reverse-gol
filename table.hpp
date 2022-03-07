#ifndef TABLE_HPP
#define TABLE_HPP

#include <vector>
#include <iostream>
#include <cstddef>

/**
 * @brief A wrapper class for std::vector that can use as a container for tables
 *
 * @tparam T The type of the elements
 */
template <typename T>
class Table
{
private:
    std::size_t height, width;
    std::vector<T> vec;

    friend std::ostream &operator<<(std::ostream &os, const Table<T> &table)
    {
        for (std::size_t i = 0; i < table.get_height(); i++)
        {
            for (std::size_t j = 0; j < table.get_width(); j++)
                os << table.vec[i * table.get_width() + j];
            os << std::endl;
        }
        return os;
    }

public:
    /**
     * @brief Construct a new Table object
     *
     */
    Table()
        : height(0), width(0), vec(std::vector<T>(0)) {}

    /**
     * @brief Construct a new Table object
     *
     * @param h Height of table
     * @param w Width of table
     */
    Table(const std::size_t h, const std::size_t w)
        : height(h), width(w), vec(std::vector<T>(h * w)) {}

    /**
     * @brief Construct a new Table object
     *
     * @param h Height of table
     * @param w Width of table
     * @param v Initial value of table cells
     */
    Table(const std::size_t h, const std::size_t w, T v)
        : height(h), width(w), vec(std::vector<T>(h * w, v)) {}

    /**
     * @brief Get the height object
     *
     * @return std::size_t
     */
    std::size_t get_height() const { return height; }

    /**
     * @brief Get the width object
     *
     * @return std::size_t
     */
    std::size_t get_width() const { return width; }

    /**
     * @brief Check whether container is empty
     *
     * @return true
     * @return false
     */
    bool empty() const { return !get_height() || !get_width(); }

    /**
     * @brief [] operator
     *
     * @param index
     * @return std::vector<T>::iterator
     */
    typename std::vector<T>::iterator operator[](std::size_t index) { return vec.begin() + index * get_width(); }

    /**
     * @brief [] operator
     *
     * @param index
     * @return std::vector<T>::const_iterator
     */
    typename std::vector<T>::const_iterator operator[](std::size_t index) const
    {
        return vec.cbegin() + index * get_width();
    }

    /**
     * @brief == operator
     *
     * @param table rvalue
     * @return true
     * @return false
     */
    bool operator==(const Table<T> &table) const
    {
        return get_height() == table.get_height() && get_width() == table.get_width() && vec == table.vec;
    }

    /**
     * @brief != operator
     *
     * @param table rvalue
     * @return true
     * @return false
     */
    bool operator!=(const Table<T> &table) const { return !(this->operator==(table)); }
};

#endif