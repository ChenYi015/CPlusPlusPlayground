#include <bitset>
#include <iostream>
#include "gtest/gtest.h"

TEST(bitset_test, intilization_test)
{
    // 声明一个 bitset 时必须要指定大小，大小必须是一个常量表达式
    std::bitset<32> bitset1; // 具有 32 位的 bitset，所有位都为 0
    std::cout << bitset1 << std::endl;

    std::bitset<32> bitset2(1U); // 具有 32 位的 bitset，最低位为 1，其他位为 0
    std::cout << bitset2 << std::endl;

    // 从 std::string 或 C-style 字符串初始化
    std::bitset<4> bitset3("11111111", 4);
    std::cout << bitset3 << std::endl;

    const char *s = "11111111";
    std::bitset<4> bitset4(s, 4);
    std::cout << bitset4 << std::endl;
}

template <int n>
void bitset_all_operations(const std::bitset<n> &b)
{
    std::cout << "bitset: " << b << std::endl;
    std::cout << "bitset.any(): " << b.any() << std::endl;
    std::cout << "bitset.all(): " << b.all() << std::endl;
    std::cout << "bitset.none(): " << b.none() << std::endl;
    std::cout << "bitset.count(): " << b.count() << std::endl;
    std::cout << "bitset.size(): " << b.size() << std::endl;
    std::cout << "bitset.to_ulong(): " << b.to_ulong() << std::endl;
    std::cout << "bitset.to_ullong(): " << b.to_ullong() << std::endl;
    std::cout << "bitset.to_string(): " << b.to_string('0', '1') << std::endl;
    std::cout << std::endl;
}

TEST(bitset_tset, bitset_operations_test)
{
    std::bitset<8> bitset1(0x0);
    bitset_all_operations<8>(bitset1);
    std::bitset<8> bitset2(0x0f);
    bitset_all_operations<8>(bitset2);
    std::bitset<8> bitset3(0xff);
    bitset_all_operations<8>(bitset3);

    std::bitset<4> bitset4(0x3);
    std::cout << "bitset4 = " << bitset4 << std::endl;
    std::cout << "bitset4.test(0): " << bitset4.test(0) << std::endl;
    std::cout << "bitset4.test(3): " << bitset4.test(3) << std::endl;
    bitset4.set(0, 0);
    std::cout << "bitset4.set(0, 0): " << bitset4 << std::endl;
    bitset4.set(0, 1);
    std::cout << "bitset4.set(0, 1): " << bitset4 << std::endl;
    bitset4.set();
    std::cout << "bitset4.set(): " << bitset4 << std::endl;
    bitset4.reset(0);
    std::cout << "bitset4.reset(0): " << bitset4 << std::endl;
    bitset4.reset();
    std::cout << "bitset4.reset(): " << bitset4 << std::endl;
    bitset4.flip(0);
    std::cout << "bitset4.flip(0): " << bitset4 << std::endl;
    bitset4.flip();
    std::cout << "bitset4.flip(): " << bitset4 << std::endl;
    std::cout << "bitset4[0]: " << bitset4[0] << std::endl;
}