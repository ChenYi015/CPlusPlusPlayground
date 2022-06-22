#include <memory>
#include "gtest/gtest.h"

/**
 * @brief 定义一个 unique_ptr 时，需要将其绑定到一个 new 返回的指针上
 *
 */
TEST(unique_ptr_test, intilization_test)
{
    std::unique_ptr<int> p1;
    std::unique_ptr<double> p2(new double(3.14));
}

/**
 * @brief unique_ptr 的拷贝构造函数被标记为 delete，因此不能调用拷贝构造函数
 *
 */
// TEST(unique_ptr_test, copy_test)
// {
//     std::unique_ptr<std::string> p1(new std::string("Hello, World!"));
//     std::unique_ptr<std::string> p2(p1);
// }

/**
 * @brief unique_ptr 的 operator= 被标记为 delete，因此不能被赋值
 *
 */
// TEST(unique_ptr_test, assignement_test)
// {
//     std::unique_ptr<std::string> p1(new std::string("Hello, World!"));
//     std::unique_ptr<std::string> p2;
//     p2 = p1;
// }