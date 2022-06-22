#ifndef TOOLS_H
#define TOOLS_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

namespace playground
{

    // Return a random vector.
    std::vector<int> random_vector(size_t size)
    {
        std::vector<int> nums(size);
        for (auto iter = nums.begin(); iter != nums.end(); ++iter)
        {
            *iter = rand();
        }
        return nums;
    }

    // Return the duration(sec) of the specified sort algorithm to sort range [first, last) into ascending order.
    template <class ForwardIterator>
    double test_sort_algorithm(ForwardIterator first, ForwardIterator last, void (*sort)(ForwardIterator, ForwardIterator))
    {
        clock_t start_t, end_t;
        start_t = clock();
        sort(first, last);
        end_t = clock();
        return (double)(end_t - start_t) / CLOCKS_PER_SEC;
    }

    // Print elements in range [first, last).
    template <class InputIterator>
    void print(InputIterator first, InputIterator last)
    {
        int count = 0;
        while (first != last)
        {
            std::cout << *first << " ";
            ++count;
            if (count % 10 == 0)
            {
                std::cout << std::endl;
            }
            ++first;
        }
        if (count % 10 != 0)
        {
            std::cout << std::endl;
        }
    }

} // namespace playground

#endif // TOOLS_H