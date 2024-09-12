#include "gtest/gtest.h"
#include "test.h"
#include "3_4_5_sorting/sort.hpp"
#include <algorithm>

TEST(SortTest, SortBasicTest) {
  uint32_t size = 11;
  auto d = GenRandomInput<uint32_t>(size, 0, 100000);
  std::vector<uint32_t> golden(d);
  sort(golden.begin(), golden.end());

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

  // QuickSort<uint32_t> quick;
  // quick.sort(d3);
  // ASSERT_EQ(d3, golden);

}