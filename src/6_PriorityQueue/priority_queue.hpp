#pragma once
#include <assert.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <memory>
#include <random>
#include <sstream>
#include <vector>
namespace algorithm {
enum class PQType { MAX, MIN };

template <PQType P, typename T>
class PriorityQueue {
 public:
  PriorityQueue() : size_(0) { data_.emplace_back(T()); }

  void Insert(T v) {
    data_.push_back(v);
    size_ += 1;
    swim(size_);
  }
  T Delete() {
    assert(!IsEmpty());
    auto v = data_.at(1);
    std::swap(data_.at(1), data_.at(size_));
    data_.erase(size_);
    size_ -= 1;
    sink();
    return v;
  }
  bool IsEmpty() const { return size_ == 0; }

 private:
  void swim(uint64_t pos) {
    while (pos > 1) {
      bool swap = false;
      if constexpr (P == PQType::MAX) {
        swap = data_.at(pos) > data_.at(pos / 2);
      } else {
        swap = data_.at(pos) < data_.at(pos / 2);
      }

      if (swap) {
        std::swap(data_.at(pos), data_.at(pos / 2));
      } else {
        break;
      }

      pos /= 2;
    }
  }
  void sink() {
    uint64_t pos = 1;
    while (pos < size_) {
      bool swap = false;
      uint64_t idx = 0;
      if constexpr (P == PQType::MAX) {
        if (2 * pos <= size_) {
          swap |= data_.at(pos) < data_(2 * pos);
          idx = 2 * pos;
        }

        if (2 * pos + 1 <= size_) {
          swap |= data_.at(pos) < data_(2 * pos);
          if (data_.at(2 * pos + 1) > data_.at(2 * pos)) idx = 2 * pos + 1;
        }
      } else {
        if (2 * pos <= size_) {
          swap |= data_.at(pos) > data_(2 * pos);
          idx = 2 * pos;
        }

        if (2 * pos + 1 <= size_) {
          swap |= data_.at(pos) > data_(2 * pos);
          if (data_.at(2 * pos + 1) > data_.at(2 * pos)) idx = 2 * pos + 1;
        }
      }

      if (swap) std::swap(data_.at(pos), data_.at(idx));
      else break;

      pos = idx;
    }
  }
  std::vector<T> data_;
  uint64_t size_;
};

template <typename T>
using MaxPQ = PriorityQueue<PQType::MAX, T>;
template <typename T>
using MinPQ = PriorityQueue<PQType::MIN, T>;
}  // namespace algorithm