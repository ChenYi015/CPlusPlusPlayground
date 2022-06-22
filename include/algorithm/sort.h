#ifndef SORT_H
#define SORT_H

#include <iterator>
#include "algorithm/algorithm.h"

namespace playground
{

    // 1. Exchange sorts

    // Bubble sort
    template <class ForwardIterator>
    void bubble_sort(ForwardIterator first, ForwardIterator last)
    {
        while (first + 1 != last)
        {
            bool swapped = false;
            ForwardIterator iter = first + 1;
            while (iter != last)
            {
                if (*first > *iter)
                {
                    playground::iter_swap(first, iter);
                    swapped = true;
                }
                ++first;
                ++iter;
            }
            if (!swapped)
            {
                break;
            }
        }
    }

    // 2. Selection sorts

    // 3. Insertion sorts

    // Insertion sort
    template <class BidirectionalIterator>
    void insertion_sort(BidirectionalIterator first, BidirectionalIterator last)
    {
        for (BidirectionalIterator iter = first + 1; iter != last; ++iter)
        {
            BidirectionalIterator curr = iter;
            while (curr != first && *(curr - 1) > *curr)
            {
                playground::iter_swap(curr - 1, curr);
                --curr;
            }
        }
    }

    // Binary insertion sort
    template <class ForwardIterator>
    void binary_insertion_sort(ForwardIterator first, ForwardIterator last)
    {
        typename std::iterator_traits<ForwardIterator>::value_type temp;
        for (ForwardIterator curr = first + 1; curr != last; ++curr)
        {
            temp = *curr;
            ForwardIterator insertion_position = playground::upper_bound(first, curr, temp);
            for (ForwardIterator iter = insertion_position; iter != curr; ++iter)
            {
                *(iter + 1) = *iter;
            }
            *insertion_position = temp;
        }
    }

    // 4. Merge sorts

} // namespace playground

#endif // SORT_H