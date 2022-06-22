#include <iostream>
#include "gtest/gtest.h"

class A
{
public:
    A() = delete;
    A(int ans) : ans(ans) {}
    A(A &a) = delete;
    A(A &&a) = default;

    static A new_instance(int ans)
    {
        return A(ans);
    }

    void print_ans()
    {
        std::cout << "My answer is " << ans << "."
                  << std::endl;
    }

private:
    int ans;
};

TEST(delete_test, test01)
{
    // 默认构造函数被标记为 delete，因此不能使用默认构造函数
    // A a1; // compile error

    A a2(42);
    a2.print_ans();

    // 拷贝构造函数的效率通常比较低，因为需要大量复制数据，因此经常需要将拷贝构造函数标记为 delete
    // A a3(a2); // compile error

    // 移动构造函数
    A a4 = A::new_instance(42);
    a4.print_ans();
}
