#include <iostream>
#include "gtest/gtest.h"


/**
 * @brief Say hello to someone.
 * 
 * @param name The name of some person, default 'World'
 */
void sayHello(std::string name = "World")
{
    std::cout << "Hello, " << name << "!" << std::endl;
}

TEST(default_parameter_test, test01)
{
    sayHello();
    sayHello("Alice");
    sayHello("Bob");
}