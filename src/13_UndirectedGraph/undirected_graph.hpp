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

class Graph {
 public:
  Graph(uint64_t vertex_num) : vertex_num_(vertex_num), adj_(vertex_num) {}

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
        ss << std::to_string(v) << " - " << std::to_string(w) << std::endl;
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

class BFSPaths {
 public:
  BFSPaths(Graph const& g, uint64_t s)
      : start_(s),
        visited_(g.V(), false),
        edge_to_(g.V(), -1u),
        dist_(g.V(), 0) {
    std::queue<uint64_t> vertex_queue;
    Bfs(g, s, vertex_queue);
  }

  bool HasPathTo(uint64_t v) { return visited_.at(v); }

  std::stack<uint64_t> PathTo(uint64_t v) {
    std::stack<uint64_t> path = {};
    if (HasPathTo(v)) {
      while (v != -1u) {
        path.push(v);
        v = edge_to_.at(v);
      }
    }
    return path;
  }

  uint64_t Distance(uint64_t v) {
    uint64_t dist = -1u;
    if (HasPathTo(v)) {
      dist = dist_.at(v);
    }
    return dist;
  }

 private:
  void Bfs(Graph const& g, uint64_t s, std::queue<uint64_t>& q) {
    q.push(s);
    while (!q.empty()) {
      auto v = q.front();
      visited_.at(v) = true;
      for (auto&& w : g.Adj(v)) {
        if (!visited_.at(w)) {
          q.push(w);
          edge_to_.at(w) = v;
          dist_.at(w) = dist_.at(v) + 1;
        }
      }
      q.pop();
    }
  }

  std::vector<bool> visited_;
  std::vector<uint64_t> edge_to_;
  std::vector<uint64_t> dist_;
  uint64_t start_;
};

class DFSPaths {
 public:
  DFSPaths(Graph const& g, uint64_t s)
      : start_(s), visited_(g.V(), false), edge_to_(g.V(), -1u) {
    Dfs(g, s);
  }

  bool HasPathTo(uint64_t v) { return visited_.at(v); }

  std::stack<uint64_t> PathTo(uint64_t v) {
    std::stack<uint64_t> path = {};
    if (HasPathTo(v)) {
      while (v != -1u) {
        path.push(v);
        v = edge_to_.at(v);
      }
    }
    return path;
  }

 private:
  void Dfs(Graph const& g, uint64_t s) {
    visited_.at(s) = true;
    for (auto&& w : g.Adj(s)) {
      if (!visited_.at(w)) {
        edge_to_.at(w) = s;
        Dfs(g, w);
      }
    }
  }

  std::vector<bool> visited_;
  std::vector<uint64_t> edge_to_;
  uint64_t start_;
};

class ConnectedComponent {
 public:
  ConnectedComponent(Graph const& g) : count_(0), visited_(g.V(), false) {
    for (uint64_t i = 0; i < g.V(); ++i) connected_.push_back(i);
    CC(g);
  }

  bool IsConnected(uint64_t v, uint64_t w) {
    return connected_.at(v) == connected_.at(w);
  }

 private:
  void Dfs(Graph const& g, uint64_t s) {
    visited_.at(s) = true;
    connected_.at(s) = count_;
    for (auto&& w : g.Adj(s)) {
      if (!visited_.at(w)) {
        Dfs(g, w);
      }
    }
  }

  void CC(Graph const& g) {
    for (uint64_t v = 0; v < g.V(); ++v) {
      if (!visited_.at(v)) {
        Dfs(g, v);
        ++count_;
      }
    }
  }

  std::vector<bool> visited_;
  std::vector<uint64_t> connected_;
  uint64_t count_;
};

class Cycle {
 public:
  Cycle(Graph const& g) : visited_(g.V(), false), edge_to_(g.V(), -1u) {
    // FIXME: exclude two form, they are both cycle:
    //          - self loop
    //          - multi edge bewteen two vertex
    for (auto v = 0; v < g.V(); ++v) {
      if (!visited_.at(v)) Dfs(g, v, v);
    }
  }

  bool IsAcycle() { return cycle_.empty(); }
  std::stack<uint64_t> CyclePath() { return cycle_; }

 private:
  void Dfs(Graph const& g, uint64_t s, uint64_t d) {
    visited_.at(s) = true;
    for (auto&& w : g.Adj(s)) {
      if (!visited_.at(w)) {
        edge_to_.at(w) = s;
        Dfs(g, w, s);
      } else {
        if (w != d && cycle_.empty()) {
          for (auto v = s; v != w; v = edge_to_.at(v)) {
            cycle_.push(v);
          }
          cycle_.push(w);
          cycle_.push(s);
        }
      }
    }
  }

  std::vector<bool> visited_;
  std::vector<uint64_t> edge_to_;
  std::stack<uint64_t> cycle_;
};

class Bipartite {
 public:
  Bipartite(Graph const& g) : visited_(g.V(), false), color_(g.V(), false) {
    for (auto v = 0; v < g.V(); ++v) {
      if (!visited_.at(v)) Dfs(g, v);
    }
  }

  bool IsBipartite() { return bipartitle_; }

 private:
  void Dfs(Graph const& g, uint64_t s) {
    visited_.at(s) = true;
    for (auto&& w : g.Adj(s)) {
      if (!visited_.at(w)) {
        color_.at(w) = !color_.at(s);
        Dfs(g, w);
      } else {
        if (color_.at(w) == color_.at(s)) bipartitle_ = false;
      }
    }
  }

  bool bipartitle_ = true;
  std::vector<bool> color_;
  std::vector<bool> visited_;
};

}  // namespace algo
