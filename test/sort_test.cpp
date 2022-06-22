#include <ctime>
#include <vector>
#include "algorithm/algorithm.h"
#include "algorithm/sort.h"
#include "common/tools.h"
#include "gtest/gtest.h"

TEST(sort_test, bubble_sort_test)
{
    std::cout << "========== Bubble Sort Performance Test ==========" << std::endl;
    for (size_t size = 10; size <= 10000000; size *= 10)
    {
        std::vector<int> nums = playground::random_vector(size);
        double duration = playground::test_sort_algorithm(nums.begin(), nums.end(), playground::bubble_sort);
        EXPECT_TRUE(playground::is_sorted(nums.begin(), nums.end()));
        std::cout << "Array of size " << size << ": " << duration << " seconds has elapsed." << std::endl;
    }
}

TEST(sort_test, insertion_sort_test)
{
    std::cout << "========== Insertion Sort Performance Test ==========" << std::endl;
    for (size_t size = 10; size <= 10000; size *= 10)
    {
        std::vector<int> nums = playground::random_vector(size);
        double duration = playground::test_sort_algorithm(nums.begin(), nums.end(), playground::insertion_sort);
        EXPECT_TRUE(playground::is_sorted(nums.begin(), nums.end()));
        std::cout << "Array of size " << size << ": " << duration << " seconds has elapsed." << std::endl;
    }
}

TEST(sort_test, binary_insertion_sort_test)
{
    std::cout << "========== Binary Insertion Sort Performance Test ==========" << std::endl;
    for (size_t size = 10; size <= 1000000; size *= 10)
    {
        std::vector<int> nums = playground::random_vector(size);
        double duration = playground::test_sort_algorithm(nums.begin(), nums.end(), playground::binary_insertion_sort);
        EXPECT_TRUE(playground::is_sorted(nums.begin(), nums.end()));
        std::cout << "Array of size " << size << ": " << duration << " seconds has elapsed." << std::endl;
    }
}