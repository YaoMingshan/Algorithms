#include "6_PriorityQueue/priority_queue.hpp"

#include <algorithm>
#include <vector>

#include "gtest/gtest.h"
#include "test.h"

using namespace algo;

TEST(PriorityTest, MaxPQTest) {
  auto maxpq = algo::MaxPQ<uint32_t>();
  auto in = GenRandomInput<uint32_t>(7, 0, 100);
  for (auto&& v : in) {
    maxpq.Insert(v);
  }
  std::vector<uint32_t> out;
  while (!maxpq.IsEmpty()) {
    out.push_back(maxpq.Delete());
  }

  std::sort(in.begin(), in.end(), [](uint32_t a, uint32_t b) { return a > b; });
  ASSERT_EQ(in, out);
}

TEST(PriorityTest, MinPQTest) {
  auto minpq = algo::MinPQ<uint32_t>();
  auto in = GenRandomInput<uint32_t>(123, 0, 100);
  for (auto&& v : in) {
    minpq.Insert(v);
  }
  std::vector<uint32_t> out;
  while (!minpq.IsEmpty()) {
    out.push_back(minpq.Delete());
  }

  std::sort(in.begin(), in.end(), [](uint32_t a, uint32_t b) { return a < b; });
  ASSERT_EQ(in, out);
}