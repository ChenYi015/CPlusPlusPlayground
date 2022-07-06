#include <iostream>
#include <thread>
#include "gtest/gtest.h"

void hello()
{
    std::cout << "Hello, C++ Concurrency!" << std::endl;
}

TEST(thread_test, test01)
{
    std::thread t(hello);
    t.join();
}