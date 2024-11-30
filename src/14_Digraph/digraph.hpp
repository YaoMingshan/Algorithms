#pragma once
#include <assert.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <list>
#include <memory>
#include <queue>
#include <random>
#include <sstream>
#include <stack>
#include <vector>

namespace algo {

class Digraph {
 public:
  Digraph(uint64_t vertex_num) : vertex_num_(vertex_num), adj_(vertex_num) {}

  void AddEdge(uint64_t v, uint64_t w) {
    adj_.at(v).emplace_back(w);
    adj_.at(w).emplace_back(v);
  }

  std::list<uint64_t>& Adj(uint64_t v) { return adj_.at(v); }
  std::list<uint64_t> Adj(uint64_t v) const { return adj_.at(v); }

  uint64_t V() const { return vertex_num_; }
  uint64_t E() const {
    uint64_t count = 0;
    for (auto&& l : adj_) {
      count += l.size();
    }
    return count / 2;  // each edge will be counted twice
  }

  std::string ToString() const {
    std::stringstream ss;
    for (uint64_t v = 0; v < V(); ++v) {
      for (auto&& w : adj_.at(v)) {
        ss << std::to_string(v) << " -> " << std::to_string(w) << std::endl;
      }
    }
    return ss.str();
  }

  uint64_t Degree(uint64_t v) const { return adj_.at(v).size(); }
  uint64_t MaxDegree() const {
    uint64_t max = 0;
    for (auto&& l : adj_) {
      if (l.size() > max) {
        max = l.size();
      }
    }
    return max;
  }
  uint64_t NumberOfSelfLoop() const {
    uint64_t count = 0;
    for (uint64_t v = 0; v < V(); ++v) {
      for (auto&& w : adj_.at(v)) {
        if (v == w) count++;
      }
    }
    return count / 2;
  }

 private:
  const uint64_t vertex_num_;
  std::vector<std::list<uint64_t>> adj_;
};

}  // namespace algo
