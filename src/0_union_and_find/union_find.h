#pragma once
#include <cstdint>
#include <vector>
#include <sstream>
#include <iostream>

class QuickFind {
 public:
  QuickFind(uint32_t N) {
    for (uint32_t i = 0; i < N; ++i) {
      id_.push_back(i);
    }
  }

  bool Connected(uint32_t p, uint32_t q) { return id_.at(p) == id_.at(q); }

  void Union(uint32_t p, uint32_t q) {
    auto idp = id_.at(p);
    auto idq = id_.at(q);
    for (auto&& it : id_) {
      if (it == idq) {
        it = idp;
      }
    }
  }

  void Print() {
    std::stringstream ss_idx;
    std::stringstream ss_val;

    for (uint i = 0; i < id_.size(); ++i) {
      ss_idx << std::to_string(i) << "  ";
      ss_val << std::to_string(id_[i]) << "  ";
    }

    std::cout << ss_idx.str() << std::endl;
    std::cout << ss_val.str() << std::endl;
  }

 private:
  std::vector<uint32_t> id_;
};

class QuickUnion {
 public:
  QuickUnion(uint32_t N) {
    for (uint32_t i = 0; i < N; ++i) {
      id_.push_back(i);
    }
  }

  uint32_t Root(uint32_t p) {
    while (p != id_[p]) {
      p = id_[p];
    }
    return p;
  }

  bool Connected(uint32_t p, uint32_t q) { return Root(p) == Root(q); }

  void Union(uint32_t p, uint32_t q) {
    auto rp = Root(p);
    auto rq = Root(q);
    id_[rp] = rq;
  }

 private:
  std::vector<uint32_t> id_;
};

class WeightedAndPathCopressionQuickUnion {
 public:
  WeightedAndPathCopressionQuickUnion(uint32_t N) {
    for (uint32_t i = 0; i < N; ++i) {
      id_.push_back(i);
    }

    sz_ = std::vector<uint32_t>(N, 1);
  }

  uint32_t Root(uint32_t p) {
    while (p != id_[p]) {
      id_[p] = id_[id_[p]];  // pach compression
      p = id_[p];
    }
    return p;
  }

  bool Connected(uint32_t p, uint32_t q) { return Root(p) == Root(q); }

  void Union(uint32_t p, uint32_t q) {
    auto rp = Root(p);
    auto rq = Root(q);

    if (rp == rq) return;
    if (sz_.at(rp) < sz_[rq]) {
      id_[rp] = rq;
      sz_.at(rq) += sz_.at(rp);
    } else {
      id_[rq] = rp;
      sz_.at(rp) += sz_.at(rq);
    }
  }

 private:
  std::vector<uint32_t> id_;
  std::vector<uint32_t> sz_;
};