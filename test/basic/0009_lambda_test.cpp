#include <algorithm>
#include <vector>
#include "common/tools.h"
#include "gtest/gtest.h"

/**
 * @brief 使用 lambda 表达式对字符串数组按照长度进行进行排序，长度相同的字符串保持相对顺序不变
 *
 */
TEST(lambda_test, test01)
{
    std::vector<std::string> words{"zero", "one", "two", "three", "four", "five", "size", "seven", "eight", "nine"};
    std::cout << "======== Before stable sort ========" << std::endl;
    playground::print(words.begin(), words.end());

    // stable_sort
    std::stable_sort(words.begin(), words.end(),
                     [](const std::string &s, const std::string &t)
                     { return s.size() < t.size(); });

    std::cout << "======== After stable sort ========" << std::endl;
    playground::print(words.begin(), words.end());
}

/**
 * @brief 使用 for_each 函数和 lambda 表达式找出字符串数组中大于等于给定长度的字符串
 *
 */
TEST(lambda_test, test02)
{
    std::vector<std::string> words{"zero", "one", "two", "three", "four", "five", "size", "seven", "eight", "nine"};
    for (int sz = 3; sz <= 6; ++sz)
    {
        std::cout << "======== words that size greater than or equal to " << sz << " ========" << std::endl;
        std::for_each(words.begin(), words.end(), [sz](const std::string &s)
                      { if (s.size() >= sz) std::cout << s << " "; });
        std::cout << std::endl;
    }
}