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

TEST(UndirectedGraphTest, DFSTest) {
  Graph g(13);
  g.AddEdge(0, 1);
  g.AddEdge(0, 2);
  g.AddEdge(0, 5);
  g.AddEdge(0, 6);
  g.AddEdge(3, 4);
  g.AddEdge(3, 5);
  g.AddEdge(4, 5);
  g.AddEdge(4, 6);
  g.AddEdge(7, 8);
  g.AddEdge(9, 10);
  g.AddEdge(9, 11);
  g.AddEdge(9, 12);
  g.AddEdge(11, 12);

  DFSPaths dfs(g, 0);
  ASSERT_TRUE(dfs.HasPathTo(3));
  auto paths = dfs.PathTo(3);
  while (!paths.empty()) {
    std::cout << std::to_string(paths.top()) << std::endl;
    paths.pop();
  }
  ASSERT_FALSE(dfs.HasPathTo(12));
}

TEST(UndirectedGraphTest, BFSTest) {
  Graph g(13);
  g.AddEdge(0, 1);
  g.AddEdge(0, 2);
  g.AddEdge(0, 5);
  g.AddEdge(0, 6);
  g.AddEdge(3, 4);
  g.AddEdge(3, 5);
  g.AddEdge(4, 5);
  g.AddEdge(4, 6);
  g.AddEdge(7, 8);
  g.AddEdge(9, 10);
  g.AddEdge(9, 11);
  g.AddEdge(9, 12);
  g.AddEdge(11, 12);

  BFSPaths bfs(g, 0);
  ASSERT_TRUE(bfs.HasPathTo(3));
  auto paths = bfs.PathTo(3);
  while (!paths.empty()) {
    std::cout << std::to_string(paths.top()) << std::endl;
    paths.pop();
  }
  ASSERT_FALSE(bfs.HasPathTo(12));
  ASSERT_EQ(bfs.Distance(3), 2);
}

TEST(UndirectedGraphTest, ConnectedComponentTest) {
  Graph g(13);
  g.AddEdge(0, 1);
  g.AddEdge(0, 2);
  g.AddEdge(0, 5);
  g.AddEdge(0, 6);
  g.AddEdge(3, 4);
  g.AddEdge(3, 5);
  g.AddEdge(4, 5);
  g.AddEdge(4, 6);
  g.AddEdge(7, 8);
  g.AddEdge(9, 10);
  g.AddEdge(9, 11);
  g.AddEdge(9, 12);
  g.AddEdge(11, 12);

  ConnectedComponent cc(g);
  EXPECT_TRUE(cc.IsConnected(0, 3));
  EXPECT_TRUE(cc.IsConnected(5, 6));
  EXPECT_TRUE(cc.IsConnected(10, 11));
  EXPECT_FALSE(cc.IsConnected(2, 8));
}

TEST(UndirectedGraphTest, CycleTest) {
  Graph g(13);
  g.AddEdge(0, 1);
  g.AddEdge(0, 2);
  g.AddEdge(0, 5);
  g.AddEdge(0, 6);
  g.AddEdge(3, 4);
  g.AddEdge(3, 5);
  g.AddEdge(4, 5);
  g.AddEdge(4, 6);
  g.AddEdge(7, 8);
  g.AddEdge(9, 10);
  g.AddEdge(9, 11);
  g.AddEdge(9, 12);
  g.AddEdge(11, 12);

  Cycle c(g);
  EXPECT_FALSE(c.IsAcycle());
  auto paths = c.CyclePath();
  while (!paths.empty()) {
    std::cout << std::to_string(paths.top()) << std::endl;
    paths.pop();
  }
}

TEST(UndirectedGraphTest, BipartiteTest) {
  Graph g(13);
  g.AddEdge(0, 1);
  g.AddEdge(0, 2);
  g.AddEdge(0, 5);
  g.AddEdge(0, 6);
  g.AddEdge(3, 4);
  g.AddEdge(3, 5);
  g.AddEdge(4, 5);
  g.AddEdge(4, 6);
  g.AddEdge(7, 8);
  g.AddEdge(9, 10);
  g.AddEdge(9, 11);
  g.AddEdge(9, 12);
  g.AddEdge(11, 12);

  Bipartite b(g);
  EXPECT_FALSE(b.IsBipartite());
}
