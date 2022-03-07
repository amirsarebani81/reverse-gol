#include <gtest/gtest.h>
#include <vector>
#include "../gol.hpp"
#include "../table.hpp"

class TableTest : public ::testing::Test
{
protected:
    Table<char> t1;
    Table<char> t2;
    Table<char> t3;

    Table<char> make_table(std::size_t height, std::size_t width, std::string input)
    {
        Table<char> result = Table<char>(height, width);
        for (std::size_t i = 0; i < height; i++)
            for (std::size_t j = 0; j < width; j++)
                result[i][j] = input[i * width + j];

        return result;
    }

    void SetUp() override
    {
        t2 = make_table(4, 5, "....*..*.*.*..*..*.*");
        t3 = make_table(4, 5, "....*..*.*.*..*..*.*");
    }
};

class GolTest : public ::testing::Test
{
protected:
    Gol gol1;
    Gol gol2;
    Gol gol3;
    Gol gol4;
    Gol gol5;
    Gol gol6;

    Table<char> res1;
    Table<char> res2;
    Table<char> res3;
    Table<char> res4;
    Table<char> res5;
    Table<char> res6;

    Table<char> make_table(std::size_t height, std::size_t width, std::string input)
    {
        Table<char> result = Table<char>(height, width);
        for (std::size_t i = 0; i < height; i++)
            for (std::size_t j = 0; j < width; j++)
                result[i][j] = input[i * width + j];

        return result;
    }

    void SetUp () override
    {
        gol1 = Gol();
        gol2 = Gol(make_table(4, 5, "....*..*.*.*..*..*.*"), 10);
        gol3 = Gol(make_table(3, 3, "*******.."), 10);
        gol4 = Gol(make_table(3, 3, "..*.*.*.*"), 5);
        gol5 = Gol(make_table(2, 2, "...."), 1);
        gol6 = Gol(make_table(5, 3, "***...****..***"), 1);

        res1 = make_table(0, 0, "");
        res2 = make_table(4, 5, "..*.*...****.***....");
        res3 = make_table(0, 0, "");
        res4 = make_table(3, 3, "..*.*.*.*");
        res5 = make_table(2, 2, "....");
        res6 = make_table(5, 3, "...*..*..*..**.");
    }
};

TEST_F(TableTest, CheckEmpty) {
    ASSERT_TRUE(t1.empty()) << "Table should be empty";
    ASSERT_FALSE(t2.empty()) << "Table should not be empty";
}

TEST_F(TableTest, CheckGetHeight) {
    ASSERT_EQ(t1.get_height(), 0) << "Table height should be 0";
    ASSERT_EQ(t2.get_height(), 4) << "Table height should be 4";
}

TEST_F(TableTest, CheckGetWidth) {
    ASSERT_EQ(t1.get_width(), 0) << "Table width should be 0";
    ASSERT_EQ(t2.get_width(), 5) << "Table width should be 5";
}

TEST_F(TableTest, CheckEqual) {
    ASSERT_TRUE(t2 == t3) << "Tables should be equal";
    ASSERT_FALSE(t1 == t2) << "Tables should not be equal";
}

TEST_F(TableTest, CheckUnequal) {
    ASSERT_TRUE(t1 != t2) << "Tables should not be equal";
    ASSERT_FALSE(t2 != t3) << "Tables should be equal";
}

TEST_F(GolTest, TestCase1)
{
    Table<char> out = gol1.solve();
    ASSERT_TRUE(out.empty()) << "Table should be empty";
    ASSERT_EQ(out, res1) << "Unexpected output";
}

TEST_F(GolTest, TestCase2)
{
    Table<char> out = gol2.solve();
    ASSERT_FALSE(out.empty()) << "Table should not be empty";
    ASSERT_EQ(out, res2) << "Unexpected output";
}

TEST_F(GolTest, TestCase3)
{
    Table<char> out = gol3.solve();
    ASSERT_TRUE(out.empty()) << "Table should be empty";
    ASSERT_EQ(out, res3) << "Unexpected output";
}

TEST_F(GolTest, TestCase4)
{
    Table<char> out = gol4.solve();
    ASSERT_FALSE(out.empty()) << "Table should not be empty";
    ASSERT_EQ(out, res4) << "Unexpected output";
}

TEST_F(GolTest, TestCase5)
{
    Table<char> out = gol5.solve();
    ASSERT_FALSE(out.empty()) << "Table should not be empty";
    ASSERT_EQ(out, res5) << "Unexpected output";
}

TEST_F(GolTest, TestCase6)
{
    Table<char> out = gol6.solve();
    ASSERT_FALSE(out.empty()) << "Table should not be empty";
    ASSERT_EQ(out, res6) << "Unexpected output";
}