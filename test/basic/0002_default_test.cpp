#include "gtest/gtest.h"

class A
{
};

TEST(default_test, test01)
{
    // 由于 A 类没有提供构造函数，编译器没生成一个默认构造函数
    // 默认构造函数不带任何参数
    A a;
}

class B
{
public:
    B(int i) : i(i) {}

private:
    int i;
};

TEST(default_test, test02)
{
    // 由于 B 类显式提供了构造函数，编译器将不会再提供默认构造函数
    // 下面的代码将会在编译期间报错 error: no matching constructor for initialization of 'B'
    // B b1(); // compile error
    B b2(42);
}

class C
{
public:
    C() = default;
    C(int i) : i(i) {}

private:
    int i;
};

TEST(default_test, test03)
{
    // 由于 C 类显式提供了构造函数，编译器将不会再提供默认构造函数
    // 为了使用编译器生成的默认构造函数，只需要在类声明中添加一个用 =default 修饰的无参构造函数即可
    C c1;
    C c2(42);
}

class Person
{
public:
    Person(std::string name, int age, std::string gender) : name(name), age(age), gender(gender) {}

private:
    std::string name;
    int age;
    std::string gender;
};