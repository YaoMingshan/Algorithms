#pragma once
#include <assert.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <memory>
#include <sstream>
#include <vector>

template<typename T>
class SelectionSort {
  void sort(std::vector<T>& d) {
    for (uint32_t i = 0; i < d.size(); ++i) {
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

template<typename T>
class InsertionSort {
  void sort(std::vector<T>& d) {
    for (uint32_t i = 0; i < d.size(); ++i) {
      for (uint32_t j = i; j >= 1; j--) {
        if (d.at(j) < d.at(j - 1)) std::swap(d.at(j), d.at(j - 1));
      }
    }
  }
};

template<typename T>
class MergeSort {
  void sort(std::vector<T>& d) {
    for (uint32_t i = 0; i < d.size(); ++i) {
      for (uint32_t j = i; j >= 1; j--) {
        if (d.at(j) < d.at(j - 1)) std::swap(d.at(j), d.at(j - 1));
      }
    }
  }
};

template<typename T>
class QuickSort {
  void sort(std::vector<T>& d) {
    for (uint32_t i = 0; i < d.size(); ++i) {
      for (uint32_t j = i; j >= 1; j--) {
        if (d.at(j) < d.at(j - 1)) std::swap(d.at(j), d.at(j - 1));
      }
    }
  }
};