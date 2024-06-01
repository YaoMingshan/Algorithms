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

  ASSERT_EQ(list_stack.Size(), 4);
  ASSERT_EQ(array_stack.Size(), 4);
  while (!list_stack.IsEmpty()) {
    auto color = list_stack.Pop();
    color.Colored();
  }

  while (!array_stack.IsEmpty()) {
    auto color = array_stack.Pop();
    color.Colored();
  }
}

TEST(StackAndQueueTest, BasicQueueTest) {
  auto list_queue = LinkedListQueue<Color>();

  list_queue.Enqueue(std::string("blue"));
  list_queue.Enqueue(std::string("red"));
  list_queue.Enqueue(std::string("green"));
  list_queue.Enqueue(std::string("yellow"));

  ASSERT_EQ(list_queue.Size(), 4);

  LinkedListQueue<Color> copy_queue0(list_queue);
  LinkedListQueue<Color> copy_queue1(list_queue);
  LinkedListQueue<Color> copy_queue2(list_queue);
  LinkedListQueue<Color> copy_queue3(list_queue);
  LinkedListQueue<Color> assign_queue;
  assign_queue = copy_queue1;
  LinkedListQueue<Color> move_queue(std::move(copy_queue2));
  LinkedListQueue<Color> move_assign_queue;
  move_assign_queue = std::move(copy_queue3);

  while (!list_queue.IsEmpty()) {
    auto color = list_queue.Dequeue();
    color.Colored();
  }

  while (!copy_queue0.IsEmpty()) {
    auto color = copy_queue0.Dequeue();
    color.Colored();
  }

  while (!assign_queue.IsEmpty()) {
    auto color = assign_queue.Dequeue();
    color.Colored();
  }

  while (!move_queue.IsEmpty()) {
    auto color = move_queue.Dequeue();
    color.Colored();
  }

  while (!move_assign_queue.IsEmpty()) {
    auto color = move_assign_queue.Dequeue();
    color.Colored();
  }
}