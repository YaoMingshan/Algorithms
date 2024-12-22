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
    // Edge: v -> w
    adj_.at(v).emplace_back(w);
  }

  std::list<uint64_t>& Adj(uint64_t v) { return adj_.at(v); }
  std::list<uint64_t> Adj(uint64_t v) const { return adj_.at(v); }

  uint64_t V() const { return vertex_num_; }
  uint64_t E() const {
    uint64_t count = 0;
    for (auto&& l : adj_) {
      count += l.size();
    }
    return count;
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

  Digraph Reverse() const {
    Digraph r(vertex_num_);
    for (uint64_t v = 0; v < V(); ++v) {
      for (auto&& w : adj_.at(v)) {
        r.AddEdge(w, v);
      }
    }
    return r;
  }

 private:
  const uint64_t vertex_num_;
  std::vector<std::list<uint64_t>> adj_;
};

// FIXME: DFS and BFS in Digraph is the same with undirected graph

class TopologicalSort {
  // Digraph has topological sort if it does not have cycle.
 public:
  TopologicalSort(Digraph g) : visited_(g.V(), false) {
    for (auto v = 0; v < g.V(); ++v) {
      if (!visited_.at(v)) DFS(g, v);
    }
  }

  std::vector<uint64_t> Order() {
    std::stack<uint64_t> temp(postorder_);
    std::vector<uint64_t> order;
    while (!temp.empty()) {
      order.push_back(temp.top());
      temp.pop();
    }
    return order;
  }

 private:
  void DFS(Digraph const& g, uint64_t v) {
    visited_.at(v) = true;
    for (auto w : g.Adj(v)) {
      if (!visited_.at(w)) DFS(g, w);
    }
    postorder_.push(v);
  }

  std::vector<bool> visited_;
  std::stack<uint64_t> postorder_;
};

class Cycle {
 public:
  Cycle(Digraph const& g) : visit_(g.V(), VisitStat::Unvisit) {
    for (auto v = 0; v < g.V(); ++v) {
      if (visit_.at(v) == VisitStat::Unvisit) DFS(g, v);
    }
  }

  bool HasCycle() { return cycle_num_ != 0; }

 private:
  void DFS(Digraph const& g, uint64_t v) {
    visit_.at(v) = VisitStat::Visiting;
    for (auto w : g.Adj(v)) {
      if (visit_.at(w) == VisitStat::Unvisit) {
        DFS(g, w);
      } else if (visit_.at(w) == VisitStat::Visiting) {
        cycle_num_ += 1;
      }
    }
    visit_.at(v) = VisitStat::Vistied;
  }
  enum VisitStat { Unvisit, Vistied, Visiting };
  std::vector<VisitStat> visit_;
  uint64_t cycle_num_ = 0;
};

class SCC {
 public:
  SCC(Digraph const& g) : scc_(g.V(), 0), visit_(g.V(), false) {
    auto gr = g.Reverse();
    auto postorder = TopologicalSort(gr).Order();
    for (auto v : postorder) {
      if (!visit_.at(v)) {
        DFS(g, v);
        counter_++;
      }
    }
  }

  std::vector<uint64_t> GetSCC() { return scc_; }

 private:
  void DFS(Digraph const& g, uint64_t v) {
    visit_.at(v) = true;
    scc_.at(v) = counter_;
    for (auto w : g.Adj(v)) {
      if (!visit_.at(w)) DFS(g, w);
    }
  }
  std::vector<uint64_t> scc_;
  std::vector<bool> visit_;
  uint64_t counter_ = 0;
};
}  // namespace algo
