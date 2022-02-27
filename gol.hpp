#ifndef GOL_HPP
#define GOL_HPP

#include <cstddef>
#include "table.hpp"

#define EMPTY '.'
#define MUSHROOM '*'

class Gol
{
private:
    Table<char> final;
    std::size_t level;

public:
    Gol(const Table<char> &t, const std::size_t l)
        : final(t), level(l) {}

    Table<char> solve() const
    {
        Table<char> t(final.get_height(), final.get_width(), EMPTY);
        const size_t bound = static_cast<std::size_t>(1) << final.get_height() * final.get_width();
        for (size_t k = 0; k < bound; k++)
        {
            const Table<char> updated_table = update(t, level);
            if (final == updated_table)
                return t;
            next(t);
        }
        return Table<char>();
    }

    void next(Table<char> &t) const
    {
        if (t[0][0] == EMPTY)
        {
            t[0][0] = MUSHROOM;
            return;
        }
        for (std::size_t i = 0; i < t.get_height(); i++)
        {
            for (std::size_t j = 0; j < t.get_width(); j++)
            {
                if (t[i][j] == MUSHROOM)
                {
                    t[i][j] = EMPTY;
                    continue;
                }
                t[i][j] = MUSHROOM;
                return;
            }
        }
    }

    Table<char> update(const Table<char> &t, const std::size_t level) const
    {
        Table<char> current = t, prev = t;
        for (std::size_t i = 0; i < level; i++)
        {
            prev = current;
            const Table<int> adj = adjacents(prev);

            for (std::size_t i = 0; i < adj.get_height(); i++)
            {
                for (std::size_t j = 0; j < adj.get_width(); j++)
                {
                    if (prev[i][j] == MUSHROOM && !(adj[i][j] == 2 || adj[i][j] == 3))
                        current[i][j] = EMPTY;
                    if (prev[i][j] == EMPTY && adj[i][j] == 3)
                        current[i][j] = MUSHROOM;
                }
            }
        }
        return current;
    }

    Table<int> adjacents(const Table<char> &table) const
    {
        Table<int> adj(table.get_height(), table.get_width(), 0);

        for (std::size_t i = 0; i < table.get_height(); i++)
        {
            for (std::size_t j = 0; j < table.get_width(); j++)
            {
                if (table[i][j] == EMPTY)
                    continue;

                for (int i_diff = -1; i_diff <= 1; i_diff++)
                {
                    for (int j_diff = -1; j_diff <= 1; j_diff++)
                    {
                        if (i_diff == 0 && j_diff == 0)
                            continue;

                        std::size_t new_i = (i + i_diff + table.get_height()) % table.get_height();
                        std::size_t new_j = (j + j_diff + table.get_width()) % table.get_width();
                        adj[new_i][new_j]++;
                    }
                }
            }
        }

        return adj;
    }
};

#endif