#include <list>
#include <tuple>
#include <vector>
#include "gtest/gtest.h"

/**
 * @brief 一个 Tuple 可以有任意数量的成员，每个成员的类型也可以不一样
 *
 */
TEST(tuple_test, initilization_test)
{
    // tuple 具有一个默认构造函数，可以将每个成员都初始化为默认值
    std::tuple<size_t, size_t, size_t> tuple1;             // 三个成员都默认初始化为 0
    std::tuple<size_t, size_t, size_t> tuple2 = {1, 2, 3}; // error
    std::tuple<size_t, size_t, size_t> tuple3{4, 5, 6};    // right

    auto tuple4 = std::make_tuple(7, 8, 9);

    std::tuple<std::string, std::vector<double>, int, std::list<int>> someVal("constants", {3.14, 2.718}, 42, {0, 1, 2, 3, 4, 5});
}

TEST(tuple_test, access_member_test)
{
    // 一个表示书店交易记录的 tuple，包含了书籍的 ISBN、数量和单价
    auto item = std::make_tuple("0-999-78345-X", 3, 20.00);

    // 使用 std::get<>() 函数来访问 tuple 的成员
    std::cout << "isbn: " << std::get<0>(item) << std::endl;

    std::cout << "count: " << std::get<1>(item) << std::endl;

    std::cout << "price before discount: " << std::get<2>(item) << std::endl;

    std::get<2>(item) *= 0.8; // 20% discount
    std::cout << "price after discount: " << std::get<2>(item) << std::endl;
}

/**
 * @brief 使用 tuple_size 和 tuple_element 两个函数来获取 tuple 的元素个数和元素类型
 *
 */
TEST(tuple_test, get_tuple_info_test)
{
    // 一个表示书店交易记录的 tuple，包含了书籍的 ISBN、数量和单价
    auto item = std::make_tuple("0-999-78345-X", 3, 20.00);

    typedef decltype(item) trans; // the type of item is trans

    size_t sz = std::tuple_size<trans>::value; // 3
    std::cout << "size of tuple: " << sz << std::endl;

    std::tuple_element<1, trans>::type cnt = std::get<1>(item);
}

TEST(tuple_test, tuple_comparison_test)
{
    std::tuple<int, int> tuple1(1, 2);
    std::tuple<int, int, int> tuple2(1, 2, 3);

    // 两个 tuple 的元素数量不同，无法进行比较
    // std::cout << "tuple1 == tuple2: " << (tuple1 == tuple2) << std::endl; // error

    std::tuple<std::string, std::string> tuple3("1", "2");

    // 两个 tuple 的元素数量相同，但是 int 和 string 无法进行比较
    // std::cout << "tuple1 == tuple3: " << (tuple1 == tuple3) << std::endl; // error

    std::tuple<int, int> tuple4(3, 4);
    std::cout << "tuple1 == tuple4: " << (tuple1 == tuple4) << std::endl;
    std::cout << "tuple1 != tuple4: " << (tuple1 != tuple4) << std::endl;
    std::cout << "tuple1 < tuple4: " << (tuple1 < tuple4) << std::endl;
    std::cout << "tuple1 <= tuple4: " << (tuple1 <= tuple4) << std::endl;
    std::cout << "tuple1 > tuple4: " << (tuple1 > tuple4) << std::endl;
    std::cout << "tuple1 >= tuple4: " << (tuple1 >= tuple4) << std::endl;
    std::cout << std::endl;

    std::tuple<int, int> tuple5(0, 4);
    std::cout << "tuple1 == tuple5: " << (tuple1 == tuple5) << std::endl;
    std::cout << "tuple1 != tuple5: " << (tuple1 != tuple5) << std::endl;
    std::cout << "tuple1 < tuple5: " << (tuple1 < tuple5) << std::endl;
    std::cout << "tuple1 <= tuple5: " << (tuple1 <= tuple5) << std::endl;
    std::cout << "tuple1 > tuple5: " << (tuple1 > tuple5) << std::endl;
    std::cout << "tuple1 >= tuple5: " << (tuple1 >= tuple5) << std::endl;
}