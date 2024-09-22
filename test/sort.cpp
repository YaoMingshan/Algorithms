#include "gtest/gtest.h"
#include "test.h"
#include "3_4_5_sorting/sort.hpp"
#include <algorithm>
#include <vector>

// Define a fixture class template
class SortingTest : public ::testing::TestWithParam<uint32_t> {};

// Test using the fixture
TEST_P(SortingTest, SortTest) {
    uint32_t size = GetParam();
    auto d = GenRandomInput<uint32_t>(size, 0, 100000);
    std::vector<uint32_t> golden(d);
    std::sort(golden.begin(), golden.end());

    std::vector<uint32_t> d1(d);
    std::vector<uint32_t> d2(d);
    std::vector<uint32_t> d3(d);

    InsertionSort<uint32_t> insert;
    insert.sort(d);
    ASSERT_EQ(d, golden);

    SelectionSort<uint32_t> select;
    select.sort(d1);
    ASSERT_EQ(d1, golden);

    MergeSort<uint32_t> merge;
    merge.sort(d2);
    ASSERT_EQ(d2, golden);

    QuickSort<uint32_t> quick;
    quick.sort(d3);
    ASSERT_EQ(d3, golden);
}

// Instantiate the test cases with different sizes
INSTANTIATE_TEST_SUITE_P(
    SortTests,
    SortingTest,
    ::testing::Values(3, 10, 57, 101, 1345) // Add more sizes as needed
);