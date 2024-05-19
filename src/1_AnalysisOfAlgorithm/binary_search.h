#pragma once
#include <assert.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <sstream>
#include <vector>

template <typename T>
class BinarySearch {
 public:
  BinarySearch(std::vector<T> input) : data_(std::move(input)) {}

  int32_t Find(T target) {
    uint32_t start = 0;
    uint32_t end = data_.size() - 1;

    std::sort(data_.begin(), data_.end());
    while (start <= end) {
      uint32_t mid = (start + end) / 2;
      if (data_.at(mid) == target) {
        return mid;
      } else if (data_.at(mid) < target) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }

    return -1;
  }

 private:
  std::vector<T> data_;
};