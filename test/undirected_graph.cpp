#include "13_UndirectedGraph/undirected_graph.hpp"

#include <algorithm>
#include <vector>

#include "gtest/gtest.h"
#include "test.h"

using namespace algo;

TEST(UndirectedGraphTest, GraphApiTest) {
  Graph g(4);
  g.AddEdge(0, 1);
  g.AddEdge(0, 2);
  g.AddEdge(0, 3);
  ASSERT_EQ(g.V(), 4);
  ASSERT_EQ(g.E(), 3);
  std::cout << g.ToString() << std::endl;
}
