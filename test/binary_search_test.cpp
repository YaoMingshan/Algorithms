#include "1_AnalysisOfAlgorithm/binary_search.h"

#include "0_UnionFind/union_find.h"
#include "gtest/gtest.h"
#include "test.h"

template <typename T>
auto BinarySearchFunc(std::vector<T> const& input, T target = 0) {
  auto bs = BinarySearch<T>(input);
  auto find = bs.Find(target);
  return find;
}

TEST(AnalysisOfAlgoTest, BinarySearchPrimaryTeset) {
  std::vector<uint32_t> input = {1, 2, 3, 4, 5};
  auto find = BinarySearchFunc(input, (uint32_t)3);
  ASSERT_EQ(find, 2);
  find = BinarySearchFunc(input, (uint32_t)1);
  ASSERT_EQ(find, 0);
  find = BinarySearchFunc(input, (uint32_t)5);
  ASSERT_EQ(find, 4);
}

TEST(AnalysisOfAlgoTest, BinarySearchTeset) {
  auto data_size = 0;
  {
    data_size = 2000;
    auto input = GenRandomInput<int32_t>(data_size, -100, 100);
    auto [result, duration] =
        MeasureFuncExecTime(BinarySearchFunc<int32_t>, input, 0);
    if (result) {
      std::cout << "Search result: " << std::to_string(*result) << std::endl;
    }
  }

  {
    data_size = 4000;
    auto input = GenRandomInput<int32_t>(data_size, -10000, 10000);
    auto [result, duration] =
        MeasureFuncExecTime(BinarySearchFunc<int32_t>, input, 0);
    if (result) {
      std::cout << "Search result: " << std::to_string(*result) << std::endl;
    }
  }
}