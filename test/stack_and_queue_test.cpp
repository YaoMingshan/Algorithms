#include "2_StacksAndQueues/stack_and_queue.h"

#include "gtest/gtest.h"
#include "test.h"

class Color {
public:
  Color(std::string color): color_(std::move(color)) {}
  void Colored() {
    std::cout<< color_ << std::endl;
  }
private:
  std::string color_;
};

TEST(StackAndQueueTest, BasicStackTest) {
  auto list_stack = LinkedListStack<Color>();
  auto array_stack = ArrayStack<Color, 4>();

  list_stack.Push(std::string("blue"));
  list_stack.Push(std::string("red"));
  list_stack.Push(std::string("green"));
  list_stack.Push(std::string("yellow"));

  array_stack.Push(std::string("blue"));
  array_stack.Push(std::string("red"));
  array_stack.Push(std::string("green"));
  array_stack.Push(std::string("yellow"));

  while (!list_stack.IsEmpty()) {
    auto color = list_stack.Pop();
    color.Colored();
  }

  while (!array_stack.IsEmpty()) {
    auto color = array_stack.Pop();
    color.Colored();
  }
}