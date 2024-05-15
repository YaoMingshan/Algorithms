#include <iostream>
#include "gtest/gtest.h"

void say_hello(){
    std::cout << "Hello, from Algo!\n";
}

TEST(HelloTest, hello) {
    say_hello();
    ASSERT_EQ(100, 100);
    std::cout << "first test" << std::endl;
}