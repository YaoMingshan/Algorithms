#pragma once
#include <assert.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <memory>
#include <random>
#include <sstream>
#include <vector>
namespace algo {

template <typename TK, typename TV>
class RBT {
 public:
  RBT() {}
  ~RBT() { DeleteNodes(root_); }

  enum class Color { Red, Black };
  struct Node {
   public:
    Node(TK k, TV v)
        : key(k),
          val(v),
          lhs(nullptr),
          rhs(nullptr),
          count(1),
          color(Color::Red) {}
    TK key;
    TV val;
    Node* lhs;
    Node* rhs;
    uint64_t count;
    Color color;
  };

  void Put(TK k, TV v) {
    root_ = Put(root_, k, v);
    root_->color = Color::Black;
  }
  Node* Get(TK k) { return Get(root_, k); }
  void Delete(TK k) {
    root_ = Delete(root_, k);
    root_->color = Color::Black;
  }
  Node* Min() { return Min(root_); }
  Node* Max() { return Max(root_); }
  Node* Floor(TK k) {
    // find lagest key <= k
    return Floor(root_, k);
  }
  Node* Ceil(TK k) {
    // find smallest key >= k
    return Ceil(root_, k);
  }
  uint64_t Size() { return Size(root_); }
  uint64_t Rank(TK k) { return Rank(root_, k); }
  Node* Select(uint64_t num) {
    // find key which rank(key) == num
    return Select(root_, num);
  }
  std::vector<TK> Inorder() {
    std::vector<TK> keys;
    Inorder(root_, keys);
    return keys;
  }

 private:
  Node* Put(Node* node, TK k, TV v) {
    if (node == nullptr) return new Node(k, v);
    if (node->key == k) {
      node->val = v;
    } else if (node->key > k) {
      node->lhs = Put(node->lhs, k, v);
    } else {
      node->rhs = Put(node->rhs, k, v);
    }

    if (!IsRed(node->lhs) && IsRed(node->rhs)) {
      node = RotateLeft(node);
    }
    if (IsRed(node->lhs) && (node->lhs->lhs != nullptr) &&
        IsRed(node->lhs->lhs)) {
      node = RotateRight(node);
    }
    if (IsRed(node->lhs) && IsRed(node->rhs)) {
      FlipColor(node);
    }
    node->count = Size(node->lhs) + Size(node->rhs) + 1;
    return node;
  }

  Node* Get(Node* node, TK k) {
    if (node == nullptr) return nullptr;
    if (node->key == k) {
      return node;
    } else if (node->key > k) {
      return Get(node->lhs, k);
    } else {
      return Get(node->rhs, k);
    }
  }

  void DeleteNodes(Node* node) {
    if (node == nullptr) return;
    DeleteNodes(node->lhs);
    DeleteNodes(node->rhs);
    delete node;
  }

  Node* Min(Node* node) {
    if (node == nullptr) return nullptr;
    auto res = Min(node->lhs);
    if (res) return res;
    return node;
  }

  Node* Max(Node* node) {
    if (node == nullptr) return nullptr;
    auto res = Max(node->rhs);
    if (res) return res;
    return node;
  }

  Node* Floor(Node* node, TK k) {
    if (node == nullptr) return nullptr;
    if (node->key > k) {
      return Floor(node->lhs, k);
    } else if (node->key < k) {
      auto res = Floor(node->rhs, k);
      if (res) return res;
      return node;
    } else {
      return node;
    }
  }

  Node* Ceil(Node* node, TK k) {
    if (node == nullptr) return nullptr;
    if (node->key < k) {
      return Ceil(node->rhs, k);
    } else if (node->key > k) {
      auto res = Ceil(node->lhs, k);
      if (res) return res;
      return node;
    } else {
      return node;
    }
  }

  uint64_t Size(Node* node) {
    if (node == nullptr) return 0;
    // node->count = Size(node->lhs) + Size(node->rhs) + 1;
    return node->count;
  }

  uint64_t Rank(Node* node, TK k) {
    if (node == nullptr) return 0;
    if (node->key > k) {
      return Rank(node->lhs);
    } else if (node->key < k) {
      return Size(node->lhs) + 1 + Rank(node->rhs);
    } else {
      return Size(node->lhs);
    }
  }
  Node* Select(Node* node, uint64_t num) {
    if (node == nullptr) return nullptr;
    if (num == 0) return Min(node);
    auto rank = Rank(node, node->key);
    if (rank < num) {
      return Select(node->rhs, num - rank - 1);
    } else if (rank > num) {
      return Select(node->lhs, num);
    } else {
      return node;
    }
  }

  Node* Delete(Node* node, TK k) {
    if (node == nullptr) return nullptr;
    Node* res = nullptr;
    if (node->key > k) {
      node->lhs = Delete(node->lhs, k);
      res = node;
    } else if (node->key < k) {
      node->rhs = Delete(node->rhs, k);
      res = node;
    } else {
      if (node->lhs == nullptr && node->rhs == nullptr) {
        delete node;
        res = nullptr;
      } else if (node->lhs != nullptr && node->rhs != nullptr) {
        Node* rhs_min = Min(node->rhs);
        Node* rhs_min_father = FindMinFather(node->rhs);
        Node* rhs_min_child = rhs_min->rhs;
        Node* seccessor = rhs_min;
        if (rhs_min_father) {
          seccessor->lhs = node->lhs;
          seccessor->rhs = node->rhs;
          rhs_min_father->lhs = rhs_min_child;
        } else {
          seccessor->lhs = node->lhs;
          seccessor->rhs = rhs_min_child;
        }
        res = seccessor;
      } else if (node->lhs) {
        res = node->lhs;
        delete node;
      } else {
        res = node->rhs;
        delete node;
      }
    }

    if (res) res->count = Size(res->lhs) + Size(res->rhs) + 1;
    return res;
  }

  Node* FindMinFather(Node* node) {
    if (node == nullptr) return nullptr;
    if (node->lhs) {
      auto res = FindMinFather(node->lhs);
      if (res) return res;
      return node;
    } else {
      return nullptr;
    }
  }

  void Inorder(Node* node, std::vector<TK>& keys) {
    if (node == nullptr) return;
    Inorder(node->lhs, keys);
    keys.push_back(node->key);
    Inorder(node->rhs, keys);
  }

  Node* RotateLeft(Node* n0) {
    /*        |                        |
             n0                       n1
             / \(red)           (red)/  \
        n0.lhs  n1                 n0    n1.rhs
               /  \               /  \
          n1.lhs  n1.rhs     n0.lhs   n1.lhs
    */
    assert(IsRed(n0->rhs));
    auto n1 = n0->rhs;
    n0->rhs = n1->lhs;
    n1->lhs = n0;
    n1->color = n0->color;
    n0->color = Color::Red;

    n0->count = Size(n0->lhs) + Size(n0->rhs) + 1;
    return n1;
  }

  Node* RotateRight(Node* n0) {
    /*            |                        |
                 n0                       n1
           (red)/  \                     /  \(red)
              n1  n0.rhs             n1.lhs  n0
             /  \                           /  \
        n1.lhs  n1.rhs                 n1.rhs  n0.rhs
    */

    assert(IsRed(n0->lhs));
    auto n1 = n0->lhs;
    n0->lhs = n1->rhs;
    n1->rhs = n0;
    n1->color = n0->color;
    n0->color = Color::Red;

    n0->count = Size(n0->lhs) + Size(n0->rhs) + 1;
    return n1;
  }

  void FlipColor(Node* node) {
    assert(IsRed(node->lhs) && IsRed(node->rhs));
    // if (node != root_) assert(!IsRed(node));
    assert(!IsRed(node));
    node->lhs->color = Color::Black;
    node->rhs->color = Color::Black;
    // if (node != root_) node->color = Color::Red;
    node->color = Color::Red;
  }

  bool IsRed(Node* node) {
    if (node == nullptr) return false;
    return node->color == Color::Red;
  }

  Node* root_ = nullptr;
};

}  // namespace algo
