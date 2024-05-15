#include "0_union_and_find/union_find.h"
#include "gtest/gtest.h"

TEST(UNION_FIND_TEST, QuickFindTest) {
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
