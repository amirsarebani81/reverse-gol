#ifndef GOL_HPP
#define GOL_HPP

#include <cstddef>
#include "table.hpp"

#define EMPTY '.'
#define MUSHROOM '*'

/**
 * @brief A class that helps to process game of life tables
 *
 */
class Gol
{
private:
    Table<char> final;
    std::size_t level;

    Table<char> update_imp(const Table<char> &table) const
    {
        Table<char> result = table;

        for (std::size_t i = 0; i < table.get_height(); i++)
        {
            for (std::size_t j = 0; j < table.get_width(); j++)
            {
                int adj = mushrooms(table, i, j);
                if (table[i][j] == MUSHROOM && !(adj == 2 || adj == 3))
                    result[i][j] = EMPTY;
                if (table[i][j] == EMPTY && adj == 3)
                    result[i][j] = MUSHROOM;
            }
        }
        return result;
    }

    void next(Table<char> &table) const
    {
        if (table[0][0] == EMPTY)
        {
            table[0][0] = MUSHROOM;
            return;
        }
        for (std::size_t i = 0; i < table.get_height(); i++)
        {
            for (std::size_t j = 0; j < table.get_width(); j++)
            {
                if (table[i][j] == EMPTY)
                {
                    table[i][j] = MUSHROOM;
                    return;
                }
                table[i][j] = EMPTY;
            }
        }
    }

public:
    /**
     * @brief Construct a new Gol object
     *
     * @param table Final table of game
     * @param lev Number of levels
     */
    Gol(const Table<char> &table, const std::size_t lev)
        : final(table), level(lev) {}

    /**
     * @brief Return initial table of game or empty table if impossible to solve
     *
     * @return Table<char>
     */
    Table<char> solve() const
    {
        Table<char> t(final.get_height(), final.get_width(), EMPTY);
        const size_t bound = static_cast<std::size_t>(1) << final.get_height() * final.get_width();
        for (size_t k = 0; k < bound; k++)
        {
            if (final == update(t, level))
                return t;
            next(t);
        }
        return Table<char>();
    }

    /**
     * @brief Update table
     *
     * @param table Initial table
     * @param level Number of updates
     * @return Table<char>
     */
    Table<char> update(const Table<char> &table, const std::size_t level = 1) const
    {
        Table<char> result = table;
        for (std::size_t i = 0; i < level; i++)
            result = update_imp(result);
        return result;
    }

    /**
     * @brief Get number of adjacent mushrooms
     *
     * @param table
     * @param index1
     * @param index2
     * @return int
     */
    int mushrooms(const Table<char> &table, const std::size_t index1, const std::size_t index2) const
    {
        int result = 0;
        for (size_t i = index1 - 1 + table.get_height(); i <= index1 + 1 + table.get_height(); i++)
        {
            for (size_t j = index2 - 1 + table.get_width(); j <= index2 + 1 + table.get_width(); j++)
            {
                if (table[i % table.get_height()][j % table.get_width()] == MUSHROOM)
                    result++;
            }
        }
        return table[index1][index2] == MUSHROOM ? --result : result;
    }
};

#endif