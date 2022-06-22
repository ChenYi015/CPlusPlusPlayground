#include <vector>
#include "algorithm/algorithm.h"
#include "gtest/gtest.h"

bool is_even(const int &num) { return (num & 0x1) == 0; }

bool is_odd(const int &num) { return (num & 0x1) == 1; }

bool is_positive(const int &num) { return num > 0; }

void print_square(const int &num) { std::cout << "square of " << num << ": " << num * num << std::endl; }

// Test whether two nums have the same parity
bool is_same_parity(const int &a, const int &b) { return ((b - a) & 0x1) == 0; }

TEST(PredicateTest, is_odd_test)
{
    EXPECT_FALSE(is_odd(2));
    EXPECT_TRUE(is_odd(1));
    EXPECT_FALSE(is_odd(0));
    EXPECT_TRUE(is_odd(-1));
    EXPECT_FALSE(is_odd(-2));
}

TEST(PredicateTest, is_positive_test)
{
    EXPECT_TRUE(is_positive(2));
    EXPECT_TRUE(is_positive(1));
    EXPECT_FALSE(is_positive(0));
    EXPECT_FALSE(is_positive(-1));
    EXPECT_FALSE(is_positive(-2));
}

TEST(AlgorithmTest, all_of_test)
{
    constexpr int n = 5;
    int nums[n] = {1, 2, 3, 4, 5};

    // all_of
    EXPECT_TRUE(playground::for_each(nums, nums + n, is_positive));
    EXPECT_FALSE(playground::all_of(nums, nums + n, is_odd));
}

TEST(AlgorithmTest, any_of_test)
{
    constexpr int n = 5;
    int nums[n] = {1, 2, 3, 4, 5};

    // any_of
    EXPECT_TRUE(playground::any_of(nums, nums + n, is_positive));
    EXPECT_TRUE(playground::any_of(nums, nums + n, is_odd));
}

TEST(AlgorithmTest, none_of_test)
{
    constexpr int n = 5;
    int nums[n] = {1, 2, 3, 4, 5};

    // none_of
    EXPECT_FALSE(playground::none_of(nums, nums + n, is_positive));
    EXPECT_FALSE(playground::none_of(nums, nums + n, is_odd));
}

TEST(AlgorithmTest, for_each_test)
{
    constexpr int n = 5;
    int nums[n] = {1, 2, 3, 4, 5};
    playground::for_each(nums, nums + n, print_square);
    playground::for_each(nums, nums + n, [](int num)
                         { std::cout << "cube of " << num << ": " << num * num * num << std::endl; });
}

TEST(AlgorithmTest, find_test)
{
    constexpr int n = 5;
    int nums[n] = {1, 2, 3, 4, 5};
    constexpr int val1 = 3;
    constexpr int val2 = 0;

    EXPECT_EQ(playground::find(nums, nums + n, val1), nums + 2);
    EXPECT_EQ(playground::find(nums, nums + n, val2), nums + n);
}

TEST(AlgorithmTest, find_if_test)
{
    std::vector<int> nums = {-2, -1, 0, 1, 2};

    EXPECT_EQ(playground::find_if(nums.begin(), nums.end(), is_odd), nums.begin() + 1);
    EXPECT_EQ(playground::find_if(nums.begin(), nums.end(), is_positive), nums.begin() + 3);
    EXPECT_EQ(playground::find_if(nums.begin(), nums.end(), [](int num)
                                  { return num > 10; }),
              nums.end());
}

TEST(AlgorithmTest, find_if_not_test)
{
    std::vector<int> nums = {2, 1, 0, -1, -2};

    EXPECT_EQ(playground::find_if_not(nums.begin(), nums.end(), is_odd), nums.begin());
    EXPECT_EQ(playground::find_if_not(nums.begin(), nums.end(), is_positive), nums.begin() + 2);
    EXPECT_EQ(playground::find_if_not(nums.begin(), nums.end(), [](int num)
                                      { return num > 10; }),
              nums.begin());
}

TEST(AlgorithmTest, find_end_test1)
{
    std::vector<int> nums1 = {1, 2, 3, 4, 5};
    std::vector<int> nums2 = {2, 3, 4};
    std::vector<int> nums3 = {2, 3, 5};

    EXPECT_EQ(playground::find_end(nums1.begin(), nums1.end(), nums2.begin(), nums2.end()), nums1.begin() + 1);
    EXPECT_EQ(playground::find_end(nums1.begin(), nums1.end(), nums3.begin(), nums3.end()), nums1.end());
}

TEST(AlgorithmTest, find_end_test2)
{
    std::vector<int> nums1 = {1, 2, 3, 4, 5};
    std::vector<int> nums2 = {2, 1, 0};
    std::vector<int> nums3 = {2, 1, 1};

    EXPECT_EQ(playground::find_end(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), is_same_parity), nums1.begin() + 1);
    EXPECT_EQ(playground::find_end(nums1.begin(), nums1.end(), nums3.begin(), nums3.end(), is_same_parity), nums1.end());
}

TEST(AlgorithmTest, find_first_of_test1)
{
    std::vector<int> nums1 = {1, 2, 3, 4, 5};
    std::vector<int> nums2 = {4, 5, 6, 7, 8};
    std::vector<int> nums3 = {6, 7, 8, 9, 10};

    EXPECT_EQ(playground::find_first_of(nums1.begin(), nums1.end(), nums2.begin(), nums2.end()), nums1.begin() + 3);
    EXPECT_EQ(playground::find_first_of(nums1.begin(), nums1.end(), nums3.begin(), nums3.end()), nums1.end());
}

TEST(AlgorithmTest, find_first_of_test2)
{
    std::vector<int> nums1 = {1, 2, 3, 4, 5};
    std::vector<int> nums2 = {4, 5, 6, 7, 8};
    std::vector<int> nums3 = {6, 7, 8, 9, 10};

    EXPECT_EQ(playground::find_first_of(nums1.begin(), nums1.end(),
                                        nums2.begin(), nums2.end(),
                                        [](int a, int b)
                                        { return a == b; }),
              nums1.begin() + 3);
    EXPECT_EQ(playground::find_first_of(nums1.begin(), nums1.end(),
                                        nums3.begin(), nums3.end(),
                                        [](int a, int b)
                                        { return a == b; }),
              nums1.end());
}

TEST(AlgorithmTest, adjacent_find_test1)
{
    std::vector<int> nums = {1, 2, 3, 3, 4, 5};
    EXPECT_EQ(playground::adjacent_find(nums.begin(), nums.end()), nums.begin() + 2);
}

TEST(AlgorithmTest, adjacent_find_test2)
{
    std::vector<int> nums = {1, 2, 3, 3, 4, 5};
    EXPECT_EQ(playground::adjacent_find(nums.begin(), nums.end(), [](int a, int b)
                                        { return a == b; }),
              nums.begin() + 2);
}

TEST(AlgorithmTest, count_test)
{
    std::vector<int> nums = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    for (int val = 1; val < 5; ++val)
    {
        EXPECT_EQ(playground::count(nums.begin(), nums.end(), val), val);
    }
}

TEST(AlgorithmTest, count_if_test)
{
    std::vector<int> nums = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    EXPECT_EQ(playground::count_if(nums.begin(), nums.end(), is_odd), 4);
}

TEST(AlgorithmTest, mismatch_test1)
{
    std::vector<int> nums1 = {1, 2, 3, 4, 5};
    std::vector<int> nums2 = {1, 2, 3, 5, 6};
    EXPECT_EQ(playground::mismatch(nums1.begin(), nums1.end(), nums2.begin(), nums2.end()),
              std::make_pair(nums1.begin() + 3, nums2.begin() + 3));
}

TEST(AlgorithmTest, mismatch_test2)
{
    std::vector<int> nums1 = {1, 2, 3, 4, 5};
    std::vector<int> nums2 = {1, 2, 3, 5, 6};
    EXPECT_EQ(playground::mismatch(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), is_same_parity),
              std::make_pair(nums1.begin() + 3, nums2.begin() + 3));
}

TEST(AlgorithmTest, search_test1)
{
    std::vector<int> nums1 = {1, 2, 3, 1, 2, 3, 1, 2, 3};
    std::vector<int> nums2 = {1, 2, 3};
    std::vector<int> nums3 = {1, 2, 3, 4};

    EXPECT_EQ(playground::search(nums1.begin(), nums1.end(), nums2.begin(), nums2.end()), nums1.begin());
    EXPECT_EQ(playground::search(nums1.begin(), nums1.end(), nums3.begin(), nums3.end()), nums1.end());
}

TEST(AlgorithmTest, search_test2)
{
    std::vector<int> nums1 = {1, 2, 3, 1, 2, 3, 1, 2, 3};
    std::vector<int> nums2 = {0, 1, 1};
    std::vector<int> nums3 = {0, 1, 0};

    EXPECT_EQ(playground::search(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), is_same_parity), nums1.begin() + 1);
    EXPECT_EQ(playground::search(nums1.begin(), nums1.end(), nums3.begin(), nums3.end(), is_same_parity), nums1.end());
}

TEST(AlgorithmTest, search_n_test1)
{
    std::vector<int> nums = {1, 2, 2, 3, 3, 3, 4, 4, 4};

    EXPECT_EQ(playground::search_n(nums.begin(), nums.end(), 2, 2), nums.begin() + 1);
    EXPECT_EQ(playground::search_n(nums.begin(), nums.end(), 3, 3), nums.begin() + 3);
    EXPECT_EQ(playground::search_n(nums.begin(), nums.end(), 4, 4), nums.end());
}

TEST(AlgorithmTest, search_n_test2)
{
    std::vector<int> nums = {1, 2, 4, 3, 6, 9, 1, 2, 4, 8};

    EXPECT_EQ(playground::search_n(nums.begin(), nums.end(), 3, 2, [](int a, int b)
                                   { return a % b == 0; }),
              nums.begin() + 7);
    EXPECT_EQ(playground::search_n(nums.begin(), nums.end(), 4, 2, [](int a, int b)
                                   { return a % b == 0; }),
              nums.end());
    EXPECT_EQ(playground::search_n(nums.begin(), nums.end(), 3, 3, [](int a, int b)
                                   { return a % b == 0; }),
              nums.begin() + 3);
}

TEST(AlgorithmTest, binary_search_test)
{
    std::vector<int> nums = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};

    auto iter = playground::binary_search(nums.begin(), nums.end(), 3);

    EXPECT_GE(iter - nums.begin(), 3);
    EXPECT_LT(iter - nums.begin(), 6);
}

TEST(AlgorithmTest, lower_bound_test)
{
    std::vector<int> nums = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};

    auto iter = playground::lower_bound(nums.begin(), nums.end(), 3);

    EXPECT_EQ(iter - nums.begin(), 3);
}

TEST(AlgorithmTest, upper_bound_test)
{
    std::vector<int> nums = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};

    auto iter = playground::upper_bound(nums.begin(), nums.end(), 3);

    EXPECT_EQ(iter - nums.begin(), 6);
}