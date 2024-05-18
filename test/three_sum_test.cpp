#include "0_UnionFind/union_find.h"
#include "1_AnalysisOfAlgorithm/three_sum.h"
#include "gtest/gtest.h"
#include <random>
#include <chrono>

std::vector<int32_t> GenRandomInput(uint32_t size) {
  std::random_device rd;
  std::mt19937 engine(rd());

  std::uniform_int_distribution<int32_t> dist(-50, 50);
  std::vector<int32_t> input;
  for (uint32_t i = 0; i < size; ++i) {
    input.push_back(dist(engine));
  }

  return input;
}

void ThreeSumRunRecorderTime(std::vector<int32_t> const& input) {
  auto start_time = std::chrono::high_resolution_clock::now();
  auto ts = ThreeSum(input);
  ts.ThreeSumEqualToZero();
  auto end_time = std::chrono::high_resolution_clock::now();

  auto duration = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);
  std::cout << "Run duration: " << duration.count() << " 秒" << std::endl;
}

TEST(AnalysisOfAlgoTest, ThreeSumTest) {
  uint32_t data_size = 4000;
  auto input0 = GenRandomInput(data_size);
  ThreeSumRunRecorderTime(input0);

  data_size = 8000;
  auto input1 = GenRandomInput(data_size);
  ThreeSumRunRecorderTime(input1);
}