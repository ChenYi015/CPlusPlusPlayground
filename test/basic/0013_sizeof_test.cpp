#include <iostream>
#include "gtest/gtest.h"

/**
 * @brief sizeof 是一个关键字，它是一个编译时运算符，用于判断变量或数据类型的字节大小。
 * sizeof 运算符可用于获取类、结构体、共用体等数据类型的大小。
 */
TEST(sizeof_test, test01)
{
    std::cout << "Size of char: " << sizeof(char) << std::endl;
    std::cout << "Size of short int: " << sizeof(short int) << std::endl;
    std::cout << "Size of int: " << sizeof(int) << std::endl;
    std::cout << "Size of long int: " << sizeof(long int) << std::endl;
    std::cout << "Size of float: " << sizeof(float) << std::endl;
    std::cout << "Size of double: " << sizeof(double) << std::endl;
    std::cout << "Size of wchar_t: " << sizeof(wchar_t) << std::endl;
}