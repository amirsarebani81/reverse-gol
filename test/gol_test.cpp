#include <gtest/gtest.h>
#include <vector>
#include "../gol.hpp"


TEST(GetInitialTable, TestCase1) {
    size_t h = 4, w = 5, l = 10;
    std::vector<char> input_v = {
    '.', '.', '.', '.', '*',
    '.', '.', '*', '.', '*',
    '.', '*', '.', '.', '*',
    '.', '.', '*', '.', '*'
    };

    std::vector<char> output_v = {
    '.', '.', '*', '.', '*',
    '.', '.', '.', '*', '*',
    '*', '*', '.', '*', '*',
    '*', '.', '.', '.', '.'
    };

    EXPECT_EQ(get_initial_table(h, w, l, input_v), output_v);
}

TEST(GetInitialTable, TestCase2) {
    size_t h = 3, w = 3, l = 10;

    std::vector<char> input_v = {
    '*', '*', '*',
    '*', '*', '*',
    '*', '*', '.'
    };

    std::vector<char> output_v(0);

    EXPECT_EQ(get_initial_table(h, w, l, input_v), output_v);
}

TEST(GetInitialTable, TestCase3) {
    size_t h = 3, w = 3, l = 5;

    std::vector<char> input_v = {
    '.', '.', '*',
    '.', '*', '.',
    '*', '.', '*'
    };

    std::vector<char> output_v = input_v;

    EXPECT_EQ(get_initial_table(h, w, l, input_v), output_v);
}

TEST(GetInitialTable, TestCase4) {
    size_t h = 2, w = 2, l = 1;

    std::vector<char> input_v = {
    '.', '.',
    '.', '.'
    };

    std::vector<char> output_v = input_v;

    EXPECT_EQ(get_initial_table(h, w, l, input_v), output_v);
}

TEST(GetInitialTable, TestCase5) {
    size_t h = 5, w = 3, l = 1;

    std::vector<char> input_v = {
    '*', '*', '*',
    '.', '.', '.',
    '*', '*', '*',
    '*', '.', '.',
    '*', '*', '*'
    };

    std::vector<char> output_v = {
    '.', '.', '.',
    '*', '.', '.',
    '*', '.', '.',
    '*', '.', '.',
    '*', '*', '.'
    };

    EXPECT_EQ(get_initial_table(h, w, l, input_v), output_v);
}
