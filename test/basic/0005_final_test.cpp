#include "gtest/gtest.h"

class Base final
{
};

/**
 * 如果一个类被 final 修饰，则该类不能被继承
 */
// class Derived : Base
// {
// }

TEST(final_test, test01)
{
    // Derived derived; // compile error
    // error: base 'Base' is marked 'final'
}