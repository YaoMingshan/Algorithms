#include "0_UnionFind/union_find.h"
#include "gtest/gtest.h"

using namespace algo;

TEST(UnionFindTest, QuickFindTest) {
  auto uf = QuickFind(8);
  uf.Union(0, 1);
  uf.Union(1, 2);
  uf.Union(2, 3);

  uf.Union(4, 5);
  uf.Union(6, 7);
  
  uf.Print();
  ASSERT_FALSE(uf.Connected(4, 7));

  uf.Union(5, 6);
  uf.Print();
  ASSERT_TRUE(uf.Connected(4, 7));
}

TEST(UnionFindTest, QuickUnionTest) {
  auto uf = QuickUnion(8);
  uf.Union(0, 1);
  uf.Union(1, 2);
  uf.Union(2, 3);

  uf.Union(4, 5);
  uf.Union(6, 7);
  
  uf.Print();
  ASSERT_FALSE(uf.Connected(4, 7));

  uf.Union(5, 6);
  uf.Print();
  ASSERT_TRUE(uf.Connected(4, 7));
}

TEST(UnionFindTest, OptUnionFindTest) {
  auto uf = WeightedAndPathCopressionQuickUnion(8);
  uf.Union(0, 1);
  uf.Union(1, 2);
  uf.Union(2, 3);

  uf.Union(4, 5);
  uf.Union(6, 7);
  
  uf.Print();
  ASSERT_FALSE(uf.Connected(4, 7));
  uf.Union(3, 4);
  uf.Print();
  uf.Union(5, 6);
  uf.Print();
  ASSERT_TRUE(uf.Connected(0, 7));
}

TEST(UnionFindTest, DeleteWithSuccessor) {
  auto uf = WeightedAndPathCopressionQuickUnion(8);
  ASSERT_EQ(uf.Remove(4), 5);
  ASSERT_EQ(uf.Remove(6), 7);
  ASSERT_EQ(uf.Remove(5), 7);
  ASSERT_EQ(uf.Remove(3), 7);
  ASSERT_EQ(uf.Remove(0), 1);
}
