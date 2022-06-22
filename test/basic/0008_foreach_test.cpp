#include <cctype>
#include <iostream>
#include <numeric>
#include <vector>
#include "gtest/gtest.h"

TEST(foreach_test, test01)
{
    std::vector<int> nums(10);
    std::iota(nums.begin(), nums.end(), 0);
    for (int num : nums)
        std::cout << num << " ";
    std::cout << std::endl;
}

TEST(foreach_test, test02)
{
    std::string s = "Hello, World!";
    for (char ch : s)
        std::cout << ch;
    std::cout << std::endl;
}

/**
 * @brief 使用范围 for 循环来统计字符串中的标点符号数量
 *
 */
TEST(foreach_test, test03)
{
    std::string s("Hello, World!!!");
    decltype(s.size()) punct_count = 0;
    for (auto ch : s)
        if (ispunct(ch))
            ++punct_count;
    std::cout << punct_count << " punctuation characters in " << s << std::endl;
}

/**
 * @brief 使用范围 for 循环来将字符串转换成大写形式
 *
 */
TEST(foreach_test, test04)
{
    std::string s("Hello, World!!!");
    for (auto &ch : s)
        ch = toupper(ch);
    std::cout << s << std::endl;
}