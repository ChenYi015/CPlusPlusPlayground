#include <iostream>
#include "gtest/gtest.h"

class Base
{
public:
    virtual void func1() { std::cout << "Base::func1()" << std::endl; }
};

class Derived : public Base
{
public:
    virtual void func1() override { std::cout << "Derived::func1()" << std::endl; }

    // 由于基类没有声明 func2() 方法
    // 因此派生类声明了一个用 override 修饰的 func2() 方法将会报错
    // virtual void func2() override { std::cout << "Derived::func2()" << std::endl; }
};

TEST(override_test, test01)
{
    Base base;
    base.func1();

    Derived derived;
    derived.func1();
}