#pragma once
#include <assert.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <memory>
#include <sstream>
#include <vector>

template <typename T>
class SelectionSort {
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
  void sort(std::vector<T>& d) {
    std::vector<T> aux(d);  // copy d
    sort(aux, d, 0, d.size() - 1);
  }

  void merge(std::vector<T>& d, std::vector<T>& aux, uint32_t lo, uint32_t mid,
             uint32_t hi) {
    uint32_t left = lo;
    uint32_t right = mid + 1;
    for (uint32_t i = lo; i < hi; ++i) {
      if (left > mid) {
        aux.at(i) = d.at(right)++ right;
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
    if (hi - lo <= 7) {
      InsertionSort isort;
      isort.sort(d, lo, hi);
      return;
    }

    uint32_t mid = (lo + hi) / 2;
    sort(aux, d, lo, mid);
    sort(aux, d, mid + 1, hi);
    merge(d, aux, lo, mid, hi);
  }
};

template <typename T>
class QuickSort {
  void sort(std::vector<T>& d) {
    for (uint32_t i = 0; i < d.size(); ++i) {
      for (uint32_t j = i; j >= 1; j--) {
        if (d.at(j) < d.at(j - 1)) std::swap(d.at(j), d.at(j - 1));
      }
    }
  }
};