#include "gtest/gtest.h"

class Person
{
public:
    Person() = default;
    Person(std::string name, int age) : name(name), age(age) {}

private:
    std::string name;
    int age;
};

TEST(decltype_test, test01)
{
    int i1;
    double d1;
    Person p1("Alice", 18);

    decltype(i1) i2; // type of i2 is int
    decltype(d1) d2; // type of d2 is double
    decltype(p1) p2; // type of p2 is Person
}

// 在 C++ 11 中，若返回值类型为 auto，则必须用 decltype 来推导返回值类型
// 在 C++ 14 中，则可以省略 decltype
template <typename T1, typename T2>
auto add(T1 x, T2 y) -> decltype(x + y)
{
    return x + y;
}

TEST(decltype_test, test02)
{
    int a = 42;
    double b = 3.14;
    auto c = add(a, b);
    EXPECT_EQ(c, 45.14);
}