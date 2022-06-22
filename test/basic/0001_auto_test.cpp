#include <iostream>
#include <numeric>
#include <vector>
#include "gtest/gtest.h"

TEST(auto_test, test01)
{
    std::vector<int> nums(10);
    std::iota(nums.begin(), nums.end(), 0);
    for (auto iter = nums.begin(); iter != nums.end(); ++iter)
    {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}
