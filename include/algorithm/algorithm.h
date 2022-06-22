#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <iterator>

namespace playground
{

    // Non-modifying sequence operations

    // Test if all elements in the range fulfill condition
    template <class InputIterator, class UnaryPredicate>
    bool all_of(InputIterator first, InputIterator last, UnaryPredicate pred)
    {
        while (first != last)
        {
            if (!pred(*first))
                return false;
            ++first;
        }
        return true;
    }

    // Test if any element in the range fulfills condition
    template <class InputIterator, class UnaryPredicate>
    bool any_of(InputIterator first, InputIterator last, UnaryPredicate pred)
    {
        while (first != last)
        {
            if (pred(*first))
                return true;
            ++first;
        }
        return false;
    }

    // Test if no element in the range fulfills condition
    template <class InputIterator, class UnaryPredicate>
    bool none_of(InputIterator first, InputIterator last, UnaryPredicate pred)
    {
        while (first != last)
        {
            if (pred(*first))
                return false;
            ++first;
        }
        return true;
    }

    // Apply function to ell elements in the range
    template <class InputIterator, class Function>
    Function for_each(InputIterator first, InputIterator last, Function fn)
    {
        while (first != last)
        {
            fn(*first);
            ++first;
        }
        return fn;
    }

    // Find value by range.
    // Returns an iterator to the first element in the range [first, last) that compares equal to val.
    // If no such element exists, last will be returned.
    template <class InputIterator, class T>
    InputIterator find(InputIterator first, InputIterator last, const T &val)
    {
        while (first != last)
        {
            if (*first == val)
            {
                return first;
            }
            ++first;
        }
        return last;
    }

    // Find element in range.
    // Returns an iterator to the first element in the range [first, last) for which pred returns true.
    // If no such element exists, last will be returned.
    template <class InputIterator, class UnaryPredicate>
    InputIterator find_if(InputIterator first, InputIterator last, UnaryPredicate pred)
    {
        while (first != last)
        {
            if (pred(*first))
            {
                return first;
            }
            ++first;
        }
        return last;
    }

    // Find element in range.
    // Returns an iterator to the first element in the range [first, last) for which pred returns false.
    // If no such element exists, last will be returned.
    template <class InputIterator, class UnaryPredicate>
    InputIterator find_if_not(InputIterator first, InputIterator last, UnaryPredicate pred)
    {
        while (first != last)
        {
            if (!pred(*first))
            {
                return first;
            }
            ++first;
        }
        return last;
    }

    // Searches the range [first1, last1) for the last occurrence of the sequence defined by [first2, last2),
    // and returns the iterator to its first element or last1 if no occurrence are found.
    template <class ForwardIterator1, class ForwardIterator2>
    ForwardIterator1 find_end(ForwardIterator1 first1, ForwardIterator1 last1,
                                          ForwardIterator2 first2, ForwardIterator2 last2)
    {
        if (first2 == last2)
        {
            return last1;
        }
        ForwardIterator1 ret = last1;
        while (first1 != last1)
        {
            ForwardIterator1 iter1 = first1;
            ForwardIterator2 iter2 = first2;
            while (*iter1 == *iter2)
            {
                ++iter1;
                ++iter2;
                if (iter2 == last2)
                {
                    ret = first1;
                    break;
                }
                if (iter1 == last1)
                {
                    return ret;
                }
            }
            ++first1;
        }
        return ret;
    }

    template <class ForwardIterator1, class ForwardIterator2, class BinaryPredicate>
    ForwardIterator1 find_end(ForwardIterator1 first1, ForwardIterator1 last1,
                                          ForwardIterator2 first2, ForwardIterator2 last2,
                                          BinaryPredicate pred)
    {
        if (first2 == last2)
        {
            return last1;
        }
        ForwardIterator1 ret = last1;
        while (first1 != last1)
        {
            ForwardIterator1 iter1 = first1;
            ForwardIterator2 iter2 = first2;
            while (pred(*iter1, *iter2))
            {
                ++iter1;
                ++iter2;
                if (iter2 == last2)
                {
                    ret = first1;
                    break;
                }
                if (iter1 == last1)
                {
                    return ret;
                }
            }
            ++first1;
        }
        return ret;
    }

    // Searches the range [first1, last1) for the first element that matches any element in [first2, last2).
    // If no such element is found, last1 will be returned.
    template <class InputIterator, class ForwardIterator>
    InputIterator find_first_of(InputIterator first1, InputIterator last1,
                                            ForwardIterator first2, ForwardIterator last2)
    {
        while (first1 != last1)
        {
            for (ForwardIterator iter = first2; iter != last2; ++iter)
            {
                if (*first1 == *iter)
                {
                    return first1;
                }
            }
            ++first1;
        }
        return last1;
    }

    // Searches the range [first1, last1) for the first element that matches any element in [first2, last2).
    // If no such element is found, last1 will be returned.
    template <class InputIterator, class ForwardIterator, class BinaryPredicate>
    InputIterator find_first_of(InputIterator first1, InputIterator last1,
                                            ForwardIterator first2, ForwardIterator last2,
                                            BinaryPredicate pred)
    {
        while (first1 != last1)
        {
            for (ForwardIterator iter = first2; iter != last2; ++iter)
            {
                if (pred(*first1, *iter))
                {
                    return first1;
                }
            }
            ++first1;
        }
        return last1;
    }

    // Searches the range [first, last) for the first occurrence of two consecutive element that are equal,
    // and returns the iterator to the first ot those two elements, or last if no such pair is found.
    template <class ForwardIterator>
    ForwardIterator adjacent_find(ForwardIterator first, ForwardIterator last)
    {
        if (first == last)
        {
            return last;
        }
        ForwardIterator next = first + 1;
        while (next != last)
        {
            if (*first == *next)
            {
                return first;
            }
            ++first;
            ++next;
        }
        return last;
    }

    // Searches the range [first, last) for the first occurrence of two consecutive element that matches,
    // and returns tht iterator to the first element of those two elements, or last if no such pair found.
    template <class ForwardIterator, class BinaryPredicate>
    ForwardIterator adjacent_find(ForwardIterator first, ForwardIterator last, BinaryPredicate pred)
    {
        if (first == last)
        {
            return last;
        }
        ForwardIterator next = first + 1;
        while (next != last)
        {
            if (pred(*first, *next))
            {
                return first;
            }
            ++first;
            ++next;
        }
        return last;
    }

    // Returns the number of elements in range [first, last) which is equal to val.
    template <class InputIterator, class T>
    typename std::iterator_traits<InputIterator>::difference_type
    count(InputIterator first, InputIterator last, const T &val)
    {
        typename std::iterator_traits<InputIterator>::difference_type ret = 0;
        while (first != last)
        {
            if (*first == val)
            {
                ++ret;
            }
            ++first;
        }
        return ret;
    }

    // Returns the number of elements in range [first, last) for which pred is true.
    template <class InputIterator, class UnaryPredicate>
    typename std::iterator_traits<InputIterator>::difference_type
    count_if(InputIterator first, InputIterator last, UnaryPredicate pred)
    {
        typename std::iterator_traits<InputIterator>::difference_type ret = 0;
        while (first != last)
        {
            if (pred(*first))
            {
                ++ret;
            }
            ++first;
        }
        return ret;
    }

    // Compares the elements in the range [first1, last1) with those in the range [first2, last2),
    // and returns the first element of both two sequences that are not equal to.
    template <class InputIterator1, class InputIterator2>
    std::pair<InputIterator1, InputIterator2>
    mismatch(InputIterator1 first1, InputIterator1 last1,
                         InputIterator2 first2, InputIterator2 last2)
    {
        while (first1 != last1 && first2 != last2 && *first1 == *first2)
        {
            ++first1;
            ++first2;
        }
        return std::make_pair(first1, first2);
    }

    // Compares the elements in the range [first1, last1) with those in the range [first2, last2),
    // and returns the first element of both two sequences that does not match.
    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    std::pair<InputIterator1, InputIterator2>
    mismatch(InputIterator1 first1, InputIterator1 last1,
                         InputIterator2 first2, InputIterator2 last2,
                         BinaryPredicate pred)
    {
        while (first1 != last1 && first2 != last2 && pred(*first1, *first2))
        {
            ++first1;
            ++first2;
        }
        return std::make_pair(first1, first2);
    }

    // Searches the range [first1, last1) for the first occurrence of the sequence defined by [first2, last2),
    // and returns the iterator to its first element or last1 if no occurrence are found.
    template <class ForwardIterator1, class ForwardIterator2>
    ForwardIterator1 search(ForwardIterator1 first1, ForwardIterator1 last1,
                                        ForwardIterator2 first2, ForwardIterator2 last2)
    {
        if (first2 == last2)
        {
            return first1;
        }
        while (first1 != last1)
        {
            ForwardIterator1 iter1 = first1;
            ForwardIterator2 iter2 = first2;
            while (*iter1 == *iter2)
            {
                ++iter1;
                ++iter2;
                if (iter2 == last2)
                {
                    return first1;
                }
                if (iter1 == last1)
                {
                    return last1;
                }
            }
            ++first1;
        }
        return last1;
    }

    // Searches the range [first1, last1) for the first occurrence of the sequence defined by [first2, last2),
    // and returns the iterator to its first element or last1 if no occurrence are found.
    template <class ForwardIterator1, class ForwardIterator2, class BinaryPredicate>
    ForwardIterator1 search(ForwardIterator1 first1, ForwardIterator1 last1,
                                        ForwardIterator2 first2, ForwardIterator2 last2,
                                        BinaryPredicate pred)
    {
        if (first2 == last2)
        {
            return first1;
        }
        while (first1 != last1)
        {
            ForwardIterator1 iter1 = first1;
            ForwardIterator2 iter2 = first2;
            while (pred(*iter1, *iter2))
            {
                ++iter1;
                ++iter2;
                if (iter2 == last2)
                {
                    return first1;
                }
                if (iter1 == last1)
                {
                    return last1;
                }
            }
            ++first1;
        }
        return last1;
    }

    // Searches the range [first, last) for the first occurrence of consecutive n element, each comparing equal to val,
    // and returns the iterator to its first element or last if no occurrence are found.
    template <class ForwardIterator, class T>
    ForwardIterator search_n(ForwardIterator first, ForwardIterator last,
                                         size_t n, const T &val)
    {
        if (n == 0)
        {
            return first;
        }
        size_t count;
        while (first != last)
        {
            ForwardIterator iter = first;
            count = 0;
            while (iter != last && *iter == val)
            {
                ++count;
                if (count == n)
                {
                    return first;
                }
                ++iter;
            }
            if (iter == last)
            {
                break;
            }
            ++first;
        }
        return last;
    }

    // Searches the range [first, last) for the first occurrence of consecutive n element, for each pred returns true,
    // and returns the iterator to its first element or last if no occurrence are found.
    template <class ForwardIterator, class T, class BinaryPredicate>
    ForwardIterator search_n(ForwardIterator first, ForwardIterator last,
                                         size_t n, const T &val,
                                         BinaryPredicate pred)
    {
        if (n == 0)
        {
            return first;
        }
        size_t count;
        while (first != last)
        {
            ForwardIterator iter = first;
            count = 0;
            while (iter != last && pred(*iter, val))
            {
                ++count;
                if (count == n)
                {
                    return first;
                }
                ++iter;
            }
            if (iter == last)
            {
                break;
            }
            ++first;
        }
        return last;
    }

    // Modifying sequence operations

    template <class ForwardIterator1, class ForwardIterator2>
    void iter_swap(ForwardIterator1 iter1, ForwardIterator2 iter2)
    {
        std::swap(*iter1, *iter2);
    }

    // Sort

    // Returns true if range [first, last) is sorted into ascending order.
    template <class ForwardIterator>
    bool is_sorted(ForwardIterator first, ForwardIterator last)
    {
        if (first == last)
        {
            return true;
        }
        ForwardIterator next = first + 1;
        while (next != last)
        {
            if (first > next)
            {
                return false;
            }
            ++first;
            ++next;
        }
        return true;
    }

    // Binary search

    // Returns iterator to any element which is equal to val in the range [first, last).
    // Returns last if no element is equal to val.
    template <class ForwardIterator, class T>
    ForwardIterator binary_search(ForwardIterator first, ForwardIterator last, const T &val)
    {
        ForwardIterator iter;
        typename std::iterator_traits<ForwardIterator>::difference_type distance, step;
        distance = std::distance(first, last);
        while (distance > 0)
        {
            iter = first;
            step = distance >> 1;
            std::advance(iter, step);
            if (*iter < val)
            {
                first = ++iter;
                distance -= step + 1;
            }
            else if (*iter == val)
            {
                first = iter;
                break;
            }
            else
            {
                distance = step;
            }
        }
        return first;
    }

    // Returns the first element in the range [first, last) which is greater than or equal to val.
    template <class ForwardIterator, class T>
    ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last, const T &val)
    {
        ForwardIterator iter;
        typename std::iterator_traits<ForwardIterator>::difference_type distance, step;
        distance = std::distance(first, last);
        while (distance > 0)
        {
            iter = first;
            step = distance / 2;
            std::advance(iter, step);
            if (*iter < val)
            {
                first = ++iter;
                distance -= step + 1;
            }
            else
            {
                distance = step;
            }
        }
        return first;
    }

    // Returns the first element in the range [first, last) which is greater than val.
    template <class ForwardIterator, class T>
    ForwardIterator upper_bound(ForwardIterator first, ForwardIterator last, const T &val)
    {
        ForwardIterator iter;
        typename std::iterator_traits<ForwardIterator>::difference_type distance, step;
        distance = std::distance(first, last);
        while (distance > 0)
        {
            iter = first;
            step = distance / 2;
            std::advance(iter, step);
            if (*iter <= val)
            {
                first = ++iter;
                distance -= step + 1;
            }
            else
            {
                distance = step;
            }
        }
        return first;
    }

} // namespace playground

#endif // ALGORITHM_H