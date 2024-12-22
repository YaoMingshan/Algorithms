#include "14_Digraph/digraph.hpp"

#include <algorithm>
#include <vector>

#include "gtest/gtest.h"
#include "test.h"

using namespace algo;

TEST(DigraphTest, DigraphApiTest) {
  Digraph g(13);
  g.AddEdge(4, 2);
  g.AddEdge(2, 3);
  g.AddEdge(3, 2);
  g.AddEdge(6, 0);
  g.AddEdge(0, 1);
  g.AddEdge(2, 0);
  g.AddEdge(11, 12);
  g.AddEdge(12, 9);
  g.AddEdge(9, 10);
  g.AddEdge(9, 11);
  g.AddEdge(7, 9);
  g.AddEdge(10, 12);
  g.AddEdge(11, 4);
  g.AddEdge(4, 3);
  g.AddEdge(3, 5);
  g.AddEdge(6, 8);
  g.AddEdge(8, 6);
  g.AddEdge(0, 5);
  g.AddEdge(5, 4);
  g.AddEdge(6, 4);
  g.AddEdge(6, 9);
  g.AddEdge(7, 6);
  ASSERT_EQ(g.V(), 13);
  ASSERT_EQ(g.E(), 22);
  std::cout << g.ToString() << std::endl;

  auto r = g.Reverse();
  std::cout << r.ToString() << std::endl;
}

TEST(DigraphTest, TopologicalSortTest) {
  Digraph g(7);
  g.AddEdge(6, 0);
  g.AddEdge(0, 1);
  g.AddEdge(0, 2);
  g.AddEdge(0, 5);
  g.AddEdge(5, 2);
  g.AddEdge(3, 2);
  g.AddEdge(3, 5);
  g.AddEdge(3, 6);
  g.AddEdge(3, 4);
  g.AddEdge(6, 4);
  g.AddEdge(1, 4);

  ASSERT_FALSE(Cycle(g).HasCycle());
  TopologicalSort topo(g);

  PrintVecInline(topo.Order());
}

TEST(DigraphTest, SCCTest) {
  Digraph g(13);
  g.AddEdge(4, 2);
  g.AddEdge(2, 3);
  g.AddEdge(3, 2);
  g.AddEdge(6, 0);
  g.AddEdge(0, 1);
  g.AddEdge(2, 0);
  g.AddEdge(11, 12);
  g.AddEdge(12, 9);
  g.AddEdge(9, 10);
  g.AddEdge(9, 11);
  g.AddEdge(7, 9);
  g.AddEdge(10, 12);
  g.AddEdge(11, 4);
  g.AddEdge(4, 3);
  g.AddEdge(3, 5);
  g.AddEdge(6, 8);
  g.AddEdge(8, 6);
  g.AddEdge(0, 5);
  g.AddEdge(5, 4);
  g.AddEdge(6, 4);
  g.AddEdge(6, 9);
  g.AddEdge(7, 6);

  SCC scc(g);
  PrintVecInline(scc.GetSCC());
}