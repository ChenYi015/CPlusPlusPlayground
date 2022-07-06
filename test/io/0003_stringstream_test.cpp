#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include "gtest/gtest.h"


struct Person
{
    std::string name;
    int age;
};

void printInfo(const Person & person)
{
    std::cout << "Person(name=" << person.name << ", age=" << person.age << ")" << std::endl;
}

/**
 * @brief Construct a new TEST object
 * istringstream 可以从 string 读数据
 * ostringstream 可以向 string 写数据
 */
TEST(stringstream_test, test01)
{
    std::string s = "Alice 18\nBob 20\nEvil 22";
    std::vector<Person> people;

    std::istringstream in(s);

    std::string line;
    while (std::getline(in, line))
    {
        std::istringstream ss(line);
        Person person;
        ss >> person.name >> person.age;
        people.push_back(person);
    }

    std::for_each(people.begin(), people.end(), printInfo);
}