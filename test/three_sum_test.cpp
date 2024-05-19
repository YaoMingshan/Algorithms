#include "1_AnalysisOfAlgorithm/three_sum.h"

#include "0_UnionFind/union_find.h"
#include "gtest/gtest.h"
#include "test.h"

void ThreeSumFunc(std::vector<int32_t> const& input) {
  auto ts = ThreeSum(input);
  ts.ThreeSumEqualToZero();
}

TEST(AnalysisOfAlgoTest, ThreeSumTest) {
  uint32_t data_size = 4000;
  auto input0 = GenRandomInput<int32_t>(data_size, -50, 50);
  MeasureFuncExecTime(ThreeSumFunc, input0);

  data_size = 8000;
  auto input1 = GenRandomInput<int32_t>(data_size, -50, 50);
  MeasureFuncExecTime(ThreeSumFunc, input1);
}