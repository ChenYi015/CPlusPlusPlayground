#include <list>
#include <memory>
#include <numeric>
#include "gtest/gtest.h"

// C++11 引入了两种智能指针模板来管理动态对象
// 智能指针和普通指针的最大区别在于由指针而非程序员负责指针所指向对象的释放
// 指针指针在 memory 头文件中定义
// shared_ptr 运行多个指针指向同一个对象
// unique_ptr 则以独占的方式指向某个对象

TEST(shared_ptr_test, test01)
{
    // 智能指针的默认初始化中保存着一个空指针
    std::shared_ptr<std::string> p1;
    auto p2 = std::make_shared<std::vector<int>>(10); // type of p2 is std::shared_ptr<std::vector<int>>

    // 智能指针的使用方式和普通指针相同
    // 使用 *ptr 返回它指向的对象
    // 在条件判断中使用智能指针，等同于检测智能指针是否为空指针
    if (p1 && p1->empty())
        *p1 = "Hello, World!";
    std::cout << *p1 << std::endl;

    std::iota(p2->begin(), p2->end(), 0);
    for (auto num : *p2)
        std::cout << num << " ";
    std::cout << std::endl;
}

TEST(shared_ptr_test, test02)
{
    std::shared_ptr<std::string> p1;
    EXPECT_EQ(p1.use_count(), 0);
    EXPECT_FALSE(p1.unique());

    *p1 = "Hello, World!";
    EXPECT_EQ(p1.use_count(), 1);
    EXPECT_TRUE(p1.unique());

    std::shared_ptr<std::string> p2(p1);
    EXPECT_EQ(p2.use_count(), 2);
    EXPECT_FALSE(p2.unique());
}