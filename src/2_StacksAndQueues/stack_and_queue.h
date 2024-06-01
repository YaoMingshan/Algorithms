#pragma once
#include <assert.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <memory>
#include <sstream>
#include <vector>

template <typename T>
class Stack {
 public:
  // rule of zero, does not declare anyone of copy construct/copy assign/move
  // construct/move assign/deconstruct
  virtual ~Stack() = default;
  virtual void Push(T const&) = 0;
  virtual T Pop() = 0;
  virtual bool IsEmpty() = 0;
  virtual uint32_t Size() = 0;
};

template <typename T>
struct LinkedListNode {
  template <typename... Args>
  LinkedListNode(Args&&... args) : val_(std::forward<Args>(args)...) {}
  // rule of five
  LinkedListNode(LinkedListNode const& n) = delete;
  LinkedListNode(LinkedListNode&& n)
      : val_(std::move(n.val_)), next_(std::move(n.next_)) {}
  LinkedListNode& operator=(LinkedListNode const& n) = delete;
  LinkedListNode& operator=(LinkedListNode&& n) {
    if (this != &n) {
      val_ = std::move(n.val_);
      next_ = std::move(n.next_);
      // n.next_ = nullptr; // do not need because move unique_ptr will be
      // nullptr after move
    }
    return *this;
  }
  ~LinkedListNode() = default;

  T val_;
  std::unique_ptr<LinkedListNode> next_ = nullptr;
};

template <typename T>
class LinkedListStack : public Stack<T> {
 public:
  LinkedListStack() : first_(nullptr) {}
  // rule of five
  LinkedListStack(LinkedListStack const& s) {
    if (!s.IsEmpty()) {
      first_ = std::make_unique<LinkedListNode<T>>(s.first_->val_);
    }
    auto ptr = first_.get();
    auto current = s.first_->next_.get();
    while (current != nullptr) {
      ptr->next_ = std::make_unique<LinkedListNode<T>>(current->val_);
      current = current->next_.get();
      ptr = ptr->next_.get();
    }
  }
  LinkedListStack(LinkedListStack&& s) noexcept = default;
  LinkedListStack& operator=(LinkedListStack const& s) {
    if (this != &s) {
      LinkedListStack temp(s);
      std::swap(first_, temp.first_);
    }
    return *this;
  }
  LinkedListStack& operator=(LinkedListStack&& s) noexcept = default;
  ~LinkedListStack() = default;

  virtual void Push(T const& v) override {
    auto node = std::make_unique<LinkedListNode<T>>(v);
    node->next_ = std::move(first_);
    first_ = std::move(node);
  }
  virtual T Pop() override {
    assert(!IsEmpty());
    auto v = first_->val_;
    first_ = std::move(first_->next_);
    return v;
  }
  virtual bool IsEmpty() override { return first_ == nullptr; }
  virtual uint32_t Size() override {
    uint32_t size = 0;
    auto current = first_.get();
    while (current != nullptr) {
      ++size;
      current = current->next_.get();
    }
    return size;
  }

 private:
  std::unique_ptr<LinkedListNode<T>> first_ = nullptr;
};

template <typename T, uint32_t INIT_CAPA>
class ArrayStack : public Stack<T> {
 public:
  ArrayStack() : init_capa_(INIT_CAPA), capacity_(INIT_CAPA) {
    stack_.reserve(INIT_CAPA);
  }
  // rule of five
  ArrayStack(ArrayStack const& s) = default;
  ArrayStack(ArrayStack&& s) = default;
  ArrayStack& operator=(ArrayStack const& s) noexcept = default;
  ArrayStack& operator=(ArrayStack&& s) noexcept = default;
  ~ArrayStack() = default;

  virtual void Push(T const& v) override {
    if (stack_.size() == capacity_) Resize(capacity_ * 2);
    stack_.push_back(v);
  }
  virtual T Pop() override {
    assert(!IsEmpty());
    auto v = stack_.back();
    stack_.pop_back();
    if (stack_.size() < capacity_ / 4 && capacity_ > init_capa_)
      Resize(capacity_ / 2);
    return v;
  }
  virtual bool IsEmpty() override { return stack_.empty(); }
  virtual uint32_t Size() override { return stack_.size(); }

 private:
  void Resize(uint32_t capacity) {
    assert(capacity >= stack_.size());
    // std::vector<T> new_stack;
    // new_stack.reserve(capacity);
    // std::copy(stack_.begin(), stack_.end(), std::back_inserter(new_stack));
    // stack_ = new_stack;
    stack_.reserve(capacity);
    capacity_ = capacity;
  }

  const uint32_t init_capa_;
  uint32_t capacity_;
  std::vector<T> stack_;
};

template <typename T>
class Queue {
 public:
  // rule of zero
  virtual ~Queue() = default;

  virtual void Enqueue(T const&) = 0;
  virtual T Dequeue() = 0;
  virtual bool IsEmpty() = 0;
  virtual uint32_t Size() = 0;
};

template <typename T>
class LinkedListQueue : public Queue<T> {
 public:
  LinkedListQueue() {}
  // rule of five
  LinkedListQueue(LinkedListQueue const& q) {
    if (!q.IsEmpty()) {
      begin_ = std::make_unique<LinkedListNode<T>>(q.begin_->val_);
    }

    auto current = q.begin_->next_.get();
    auto ptr = begin_.get();

    while (current != nullptr) {
      ptr->next_ = std::make_unique<LinkedListNode<T>>(current->val_);
      current = current->next_.get();
      ptr = ptr->next_.get();
    }

    end_ = ptr;
  }
  LinkedListQueue(LinkedListQueue&&) noexcept = default;
  LinkedListQueue& operator=(LinkedListQueue const& q) {
    if (this != &q) {
      LinkedListQueue temp(q);
      swap(begin_, temp.begin_);
      swap(end_, temp.end_);
    }
    return *this;
  }
  LinkedListQueue& operator=(LinkedListQueue&&) noexcept = default;
  ~LinkedListQueue() = default;

  virtual void Enqueue(T const& v) override {
    auto node = std::make_unique<LinkedListNode<T>>(v);
    if (IsEmpty()) {
      begin_ = std::move(node);
      end_ = begin_.get();
    } else {
      end_.next_ = std::move(node);
      end_ = end_.next_.get();
    }
  }
  virtual T Dequeue() override {
    assert(!IsEmpty());
    auto v = std::move(begin_->val_);
    begin_ = std::move(begin_->next_);
    return v;
  }
  virtual bool IsEmpty() override { return begin_ == nullptr; }
  virtual uint32_t Size() override {
    uint32_t size = 0;
    auto current = begin_.get();
    while (current != nullptr) {
      ++size;
      current = current->next_.get();
    }

    return size;
  }

 private:
  std::unique_ptr<LinkedListNode<T>> begin_ = nullptr;
  LinkedListNode<T>* end_ = nullptr;
};
