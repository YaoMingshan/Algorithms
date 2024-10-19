#pragma once
#include <assert.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <sstream>
#include <vector>

namespace algorithm {

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

template <typename T>
class BitonicSearch {
 public:
  BitonicSearch(std::vector<T> input) : data_(std::move(input)) {}

  int32_t Find(T target, uint32_t start, uint32_t end) {
    // {1, 2, 3, 4, 3, 2, 1}
    uint32_t mid = (start + end) / 2;
    if (data_.at(mid) == target) {
      return mid;
    } else if (start == end) {
      return -1;
    } else if (data_.at(mid) > target) {
      if (data_.at(start) > target && data_.at(end) > target) {
        return -1;
      }
      if (data_.at(start) <= target) {
        auto new_end = mid == start ? mid : mid - 1;
        auto find = Find(target, start, new_end);
        if (find >= 0) return find;
      }
      if (data_.at(end) <= target) {
        auto find = Find(target, mid + 1, end);
        if (find >= 0) return find;
      }

      return -1;
    } else {
      // data_.at(mid) < target
      if (data_.at(mid + 1) > data_.at(mid)) {
        auto find = Find(target, mid + 1, end);
        return find;
      } else {
        auto new_end = mid == start ? mid : mid - 1;
        auto find = Find(target, start, new_end);
        return find;
      }
    }

    assert(false);
    return -1;
  }

  int32_t Find(T target) {
    return Find(target, 0, data_.size() - 1);
  }

 private:
  std::vector<T> data_;
};

}  // namespace algorithm
