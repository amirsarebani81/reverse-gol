#include <gtest/gtest.h>
#include <vector>
#include "../gol.hpp"
#include "../table.hpp"


TEST(GetInitialTable, TestCase1) {
    size_t h = 4, w = 5, l = 10;
    Table<char> i(h, w, '.');
    i.set(0, 4, '*');
    i.set(1, 2, '*');
    i.set(1, 4, '*');
    i.set(2, 1, '*');
    i.set(2, 4, '*');
    i.set(3, 2, '*');
    i.set(3, 4, '*');
    Gol gol(i, l);
    Table<char> r = gol.solve();
    Table<char> o(h, w, '.');
    o.set(0, 2, '*');
    o.set(0, 4, '*');
    o.set(1, 3, '*');
    o.set(1, 4, '*');
    o.set(2, 0, '*');
    o.set(2, 1, '*');
    o.set(2, 3, '*');
    o.set(2, 4, '*');
    o.set(3, 0, '*');

    ASSERT_FALSE(r.empty());
    ASSERT_TRUE(r.equal(o));
}

TEST(GetInitialTable, TestCase2) {
    size_t h = 3, w = 3, l = 10;
    Table<char> i(h, w, '*');
    i.set(2, 2, '.');
    Gol gol(i, l);
    Table<char> r = gol.solve();

    ASSERT_TRUE(r.empty());
}

TEST(GetInitialTable, TestCase3) {
    size_t h = 3, w = 3, l = 5;
    Table<char> i(h, w, '.');
    i.set(0, 2, '*');
    i.set(1, 1, '*');
    i.set(2, 0, '*');
    i.set(2, 2, '*');
    Gol gol(i, l);
    Table<char> r = gol.solve();

    ASSERT_FALSE(r.empty());
    ASSERT_TRUE(r.equal(i));
}

TEST(GetInitialTable, TestCase4) {
    size_t h = 2, w = 2, l = 1;
    Table<char> i(h, w, '.');
    Gol gol(i, l);
    Table<char> r = gol.solve();

    ASSERT_FALSE(r.empty());
    ASSERT_TRUE(r.equal(i));
}

TEST(GetInitialTable, TestCase5) {
    size_t h = 5, w = 3, l = 1;

    Table<char> i(h, w, '*');
    i.set(1, 0, '.');
    i.set(1, 1, '.');
    i.set(1, 2, '.');
    i.set(3, 1, '.');
    i.set(3, 2, '.');
    Gol gol(i, l);
    Table<char> r = gol.solve();
    Table<char> o(h, w, '.');
    o.set(1, 0, '*');
    o.set(2, 0, '*');
    o.set(3, 0, '*');
    o.set(4, 0, '*');
    o.set(4, 1, '*');

    ASSERT_FALSE(r.empty());
    ASSERT_TRUE(r.equal(o));
}
