#include <exception>
#include "gtest/gtest.h"

/**
 * noexcept 既是一个函数说明符，也是一个一元运算符
 *
 *
 * 如果一个函数不会抛出异常，则可以大大简化调用方的代码
 * 另外，编译器也可以对其执行某些特殊的优化操作
 * C++ 11 引入了 noexcept specification 用来显式说明某个函数不会抛出异常
 * 编译器并不会在编译时检查 noexcept 说明，即时用 noexcept 说明，而函数实际上抛出了异常，编译器也能顺利编译通过。
 */

void func1() { throw std::exception(); }

// void func2() noexcept { throw std::exception(); }

void func3() noexcept {}

TEST(noexcept_test, test01)
{
    EXPECT_ANY_THROW(func1());
}

TEST(noexcept_test, test02)
{
    // 如果一个有 noexcept 说明符的函数在运行时抛出了异常，则程序将会 abort
    // EXPECT_ANY_THROW(func2());
}

TEST(noexcept_test, test03)
{
    EXPECT_NO_THROW(func3());
}

// noexcept 作为一个一元运算符，它的返回值类型是一个 bool 类型的右值常量表达式，由于表示给定表达式是否会抛出异常
// 和 sizeof 类似，noexcept 并不会对表达式进行求值

TEST(noexcept_test, test04)
{
    EXPECT_FALSE(noexcept(func1()));
}

TEST(noexcept_test, test05)
{
    EXPECT_TRUE(noexcept(func3()));
}