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

template <typename T>
class Shuffle {
 public:
  void shuffle(std::vector<T>& d) {
    if (d.size() <= 1) return;
    for (uint32_t i = 1; i < d.size(); ++i) {
      std::mt19937 gen(0x1234);
      std::uniform_int_distribution<> distrib(0, i);
      uint32_t pos = distrib(gen);
      std::swap(d.at(i), d.at(pos));
    }
  }
};
template <typename T>
class SelectionSort {
 public:
  void sort(std::vector<T>& d) { return sort(d, 0, d.size() - 1); }
  void sort(std::vector<T>& d, uint32_t lo, uint32_t hi) {
    for (uint32_t i = lo; i <= hi; ++i) {
      uint32_t smallest = i;
      for (uint32_t j = i + 1; j < d.size(); ++j) {
        if (d.at(j) < d.at(smallest)) {
          smallest = j;
        }
      }

      if (smallest != i) std::swap(d.at(i), d.at(smallest));
    }
  }
};

template <typename T>
class InsertionSort {
 public:
  void sort(std::vector<T>& d) { sort(d, 0, d.size() - 1); }
  void sort(std::vector<T>& d, uint32_t lo, uint32_t hi) {
    for (uint32_t i = lo; i <= hi; ++i) {
      for (uint32_t j = i; j >= 1; j--) {
        if (d.at(j) < d.at(j - 1)) std::swap(d.at(j), d.at(j - 1));
      }
    }
  }
};

template <typename T>
class MergeSort {
 public:
  void sort(std::vector<T>& d) {
    std::vector<T> aux(d);  // copy d
    sort(aux, d, 0, d.size() - 1);
  }

  void merge(std::vector<T>& d, std::vector<T>& aux, uint32_t lo, uint32_t mid,
             uint32_t hi) {
    uint32_t left = lo;
    uint32_t right = mid + 1;
    for (uint32_t i = lo; i <= hi; ++i) {
      if (left > mid) {
        aux.at(i) = d.at(right);
        ++right;
      } else if (right > hi) {
        aux.at(i) = d.at(left);
        ++left;
      } else if (d.at(left) <= d.at(right)) {
        aux.at(i) = d.at(left);
        ++left;
      } else {
        aux.at(i) = d.at(right);
        ++right;
      }
    }
  }

  void sort(std::vector<T>& d, std::vector<T>& aux, uint32_t lo, uint32_t hi) {
    // if (hi - lo <= 7) {
    //   InsertionSort<T> isort;
    //   isort.sort(d, lo, hi);
    //   return;
    // }
    if (hi <= lo) return;
    uint32_t mid = (lo + hi) / 2;
    sort(aux, d, lo, mid);
    sort(aux, d, mid + 1, hi);
    merge(d, aux, lo, mid, hi);
  }
};

template <typename T>
class QuickSort {
 public:
  void sort(std::vector<T>& d) {
    Shuffle<T> s;
    s.shuffle(d);
    sort(d, 0, d.size() - 1);
  }

  void sort(std::vector<T>& d, uint32_t lo, uint32_t hi) {
    if (hi <= lo) return;
    if (hi == lo + 1) {
      if (d.at(lo) > d.at(hi)) {
        std::swap(d.at(lo), d.at(hi));
      }
      return;
    }
    uint32_t mid = (lo + hi) / 2;
    auto idx = midian3(d, lo, mid, hi);
    std::swap(d.at(lo), d.at(idx));

    auto pivot = d.at(lo);
    uint32_t i = lo + 1;
    uint32_t j = hi;
    while (i <= j) {
      if (d.at(i) > pivot && d.at(j) < pivot) {
        std::swap(d.at(i), d.at(j));
        ++i;
        --j;
      } else if (d.at(i) > pivot && d.at(j) >= pivot) {
        --j;
      } else if (d.at(i) <= pivot && d.at(j) < pivot) {
        ++i;
      } else {
        ++i;
        --j;
      }
    }

    if (lo < i) std::swap(d.at(lo), d.at(i - 1));

    if (lo < i - 1) sort(d, lo, i - 2);
    if (i < hi) sort(d, i , hi);
  }

  uint32_t midian3(std::vector<T>& d, uint32_t lo, uint32_t mid, uint32_t hi) {
    auto&& a = d.at(lo);
    auto&& b = d.at(mid);
    auto&& c = d.at(hi);
    if ((a <= b && a >= c) || (a <= c && a >= b)) {
      return lo;
    } else if ((b <= a && b >= c) || (b <= c && b >= a)) {
      return mid;
    } else {
      return hi;
    }
  }
};