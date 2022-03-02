#include <gtest/gtest.h>
#include <vector>
#include "../gol.hpp"
#include "../table.hpp"

Table<char> make_table(std::size_t height, std::size_t width, std::string input)
{
    Table<char> result = Table<char>(height, width);
    for (std::size_t i = 0; i < height; i++)
        for (std::size_t j = 0; j < width; j++)
            result[i][j] = input[i * width + j];

    return result;
}

// ------------------------------------------------------------------
/*
in
4 5 10
....*
..*.*
.*..*
..*.*

out
..*.*
...**
**.**
*....
*/
TEST(GolSolve, TestCase1)
{
    std::string in = "....*..*.*.*..*..*.*";
    std::string out = "..*.*...****.***....";
    Table<char> res = Gol(make_table(4, 5, in), 10).solve();

    ASSERT_FALSE(res.empty());
    ASSERT_EQ(res, make_table(4, 5, out));
}

// ------------------------------------------------------------------
/*
in
3 3 10
***
***
*..

out
impossible
*/
TEST(GolSolve, TestCase2)
{
    std::string in = "*******..";
    Table<char> res = Gol(make_table(3, 3, in), 10).solve();

    ASSERT_TRUE(res.empty());
}

// ------------------------------------------------------------------
/*
in
3 3 5
..*
.*.
*.*

out
..*
.*.
*.*
*/
TEST(GolSolve, TestCase3)
{
    std::string in = "..*.*.*.*";
    Table<char> res = Gol(make_table(3, 3, in), 5).solve();

    ASSERT_FALSE(res.empty());
    ASSERT_EQ(res, make_table(3, 3, in));
}

// ------------------------------------------------------------------
/*
in
2 2 1
..
..

out
..
..
*/
TEST(GolSolve, TestCase4)
{
    std::string in = "....";
    Table<char> res = Gol(make_table(2, 2, in), 1).solve();

    ASSERT_FALSE(res.empty());
    ASSERT_EQ(res, make_table(2, 2, in));
}

// ------------------------------------------------------------------
/*
in
5 3 1
***
...
***
*..
***

out
...
*..
*..
*..
**.
*/
TEST(GolSolve, TestCase5)
{
    std::string in = "***...****..***";
    std::string out = "...*..*..*..**.";
    Table<char> res = Gol(make_table(5, 3, in), 1).solve();

    ASSERT_FALSE(res.empty());
    ASSERT_EQ(res, make_table(5, 3, out));
}
