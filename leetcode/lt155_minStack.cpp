#include "lt.h"

class MinStack {
 public:
  MinStack() {}

  void push(int val) {
    stack.push(val);
    if (minStack.empty() || val <= minStack.top()) {
      minStack.push(val);
    } else {
      minStack.push(minStack.top());
    }
  }

  void pop() {
    stack.pop();
    minStack.pop();
  }

  int top() { return stack.top(); }

  int getMin() { return minStack.top(); }

 private:
  std::stack<int> stack;
  std::stack<int> minStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

TEST(LeetCodeTest, lt155test) {
  MinStack* obj = new MinStack();
  obj->push(-2);
  obj->push(0);
  obj->push(-3);
  EXPECT_EQ(obj->getMin(), -3);
  obj->pop();
  EXPECT_EQ(obj->top(), 0);
  EXPECT_EQ(obj->getMin(), -2);
}