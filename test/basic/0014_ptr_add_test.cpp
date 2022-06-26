#include <iostream>
#include "gtest/gtest.h"

TEST(ptr_add_test, test01)
{
    int arr1[10];
    int *arr2 = new int[10];

    for (int i = 0; i < 10; ++i)
    {
        arr1[i] = i;
        std::cout << "arr1[" << i << "]: " << arr1[i] << std::endl;
    }

    for (int i = 0; i < 10; ++i)
    {
        arr2[i] = i + 10;
        std::cout << "arr2[" << i << "]: " << arr2[i] << std::endl;
    }
}

TEST(ptr_add_test, test02)
{
    constexpr int n = 4;
    int arr1[n];
    int *arr2 = new int[n];

    for (int i = 0; i < n; ++i)
    {
        std::cout << "&arr1[" << i << "] = " << &arr1[i] << std::endl;
    }

    for (int i = 0; i < n; ++i)
    {
        std::cout << "arr2 + i = " << arr2 + i << std::endl;
    }
}

TEST(ptr_add_test, test03)
{
    constexpr int n = 2;
    int arr1[n][n];
    int **arr2 = new int *[n];
    for (int i = 0; i < n; ++i)
    {
        arr2[i] = new int[n];
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cout << "&arr1[" << i << "][" << j << "] = " << &arr1[i][j] << std::endl;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cout << "&arr2[" << i << "][" << j << "] = " << arr2 + i * n + j << std::endl;
        }
    }
}