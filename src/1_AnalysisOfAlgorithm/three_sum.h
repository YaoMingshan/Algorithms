#pragma once
#include <assert.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <sstream>
#include <vector>

class ThreeSum {
 public:
  ThreeSum(std::vector<int32_t> data) : data_(std::move(data)) {}

  void ThreeSumEqualToZero() {
    uint32_t combination = 0;
    std::sort(data_.begin(), data_.end());
    for (uint32_t i = 0; i < data_.size(); ++i) {
      uint32_t start = i + 1;
      uint32_t end = data_.size() - 1;
      while (start < end) {
        int32_t sum = data_.at(i) + data_.at(start) + data_.at(end);
        if (sum == 0) {
          std::stringstream ss;
          ss << std::to_string(data_.at(i)) << " + "
             << std::to_string(data_.at(start)) << " + "
             << std::to_string(data_.at(end)) << " = 0";
          // std::cout << ss.str() << std::endl;
          combination++;
          start++;
        } else if (sum < 0) {
          start++;
        } else {
          end--;
        }
      }
    }

    std::cout << "There are " << std::to_string(combination)
              << " kinds of combination." << std::endl;
  }

 private:
  std::vector<int32_t> data_;
};