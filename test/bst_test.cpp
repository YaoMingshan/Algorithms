#include "8_BinarySearchTree/bst.hpp"

#include <algorithm>
#include <vector>

#include "gtest/gtest.h"
#include "test.h"

using namespace algo;

TEST(BstTest, InsertTest) {
  auto in = GenRandomInput<uint32_t>(64, 0, 100);
  std::sort(in.begin(), in.end());
  auto last = std::unique(in.begin(), in.end());
  in.erase(last, in.end());

  auto bst = BST<uint32_t, uint32_t>();

  std::mt19937 gen(42);
  std::shuffle(in.begin(), in.end(), gen);
  for (size_t i = 0; i < in.size(); ++i) {
    auto e = in.at(i);
    // std::cout << e << std::endl;
    bst.Put(e, e);
  }

  auto inorder = bst.Inorder();

  std::sort(in.begin(), in.end());
  ASSERT_EQ(in, inorder);
  ASSERT_EQ(bst.Size(), in.size());
  for (auto e : inorder) {
    std::cout << e << std::endl;
  }

  std::cout << "min: " << bst.Min()->key << std::endl;
  std::cout << "max: " << bst.Max()->key << std::endl;
  std::cout << "fllor: " << bst.Floor(76)->key << std::endl;
  std::cout << "ceil: " << bst.Ceil(76)->key << std::endl;

  {
    bst.Delete(70);
    inorder = bst.Inorder();
    auto it = std::find(in.begin(), in.end(), 70);
    in.erase(it);
    ASSERT_EQ(in, inorder);
  }

  {
    bst.Delete(34);
    inorder = bst.Inorder();
    auto it = std::find(in.begin(), in.end(), 34);
    in.erase(it);
    ASSERT_EQ(in, inorder);
  }

  {
    bst.Delete(65);
    inorder = bst.Inorder();
    auto it = std::find(in.begin(), in.end(), 65);
    in.erase(it);
    ASSERT_EQ(in, inorder);
  }
}
