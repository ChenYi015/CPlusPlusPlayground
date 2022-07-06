#include <iostream>
#include "gtest/gtest.h"

// class A
// {
// public:
//     static int getInstanceCount() { return instanceCount; }
//     static void setInstanceCount(int count) { instanceCount = count; }

// private:
//     static int instanceCount;

// public:
//     A() : id(instanceCount) { ++instanceCount; }

// private:
//     int id;
// };

// TEST(static_member_test, tset01)
// {
//     A::setInstanceCount(0);
//     EXPECT_EQ(0, A::getInstanceCount());

//     A a1;
//     EXPECT_EQ(1, A::getInstanceCount());

//     A a2;
//     EXPECT_EQ(2, A::getInstanceCount());
// }