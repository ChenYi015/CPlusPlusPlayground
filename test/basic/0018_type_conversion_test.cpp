#include <iostream>
#include "gtest/gtest.h"

class Complex
{
public:
    Complex() : Complex(0.0, 0.0) { }
    Complex(double real, double imag) : real(real), imag(imag) { }

    Complex(double real) : Complex(real, 0.0) { }

    friend std::ostream & operator<<(std::ostream & out, Complex & complex);
    friend Complex operator+(const Complex & c1, const Complex & c2);

private:
    double real;
    double imag;
};

std::ostream & operator<<(std::ostream & out, Complex & complex)
{
    out << complex.real << " + " << complex.imag << "i";
    return out;
}

Complex operator+(const Complex & c1, const Complex & c2)
{
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

TEST(type_conversion_test, implicit_type_conversion_test)
{
    Complex c1(1.0, 2.0);
    Complex c2(20.0);
    Complex c3 = c1 + c2;
    Complex c4 = c1 + 20.0;

    std::cout << "c1: " << c1 << std::endl;
    std::cout << "c2: " << c2 << std::endl;
    std::cout << "c3: " << c3 << std::endl;
    std::cout << "c4: " << c4 << std::endl;
}

class Person
{
public:
    /**
     * @brief Suppress implicit type conversion with explicit keyword
     * 
     * @param name 
     */
    explicit Person(const std::string & name) : name(name) { }

    std::string getName() const { return name; }

private:
    std::string name;
};

void sayHello(const Person & person)
{
    std::cout << "Hello, " << person.getName() << "!" << std::endl;
}


/**
 * @brief Suppress implicit type conversion test
 */
TEST(type_conversion_test, suppress_implicit_type_conversion_test)
{
    Person alice("Alice");
    sayHello(alice);

    // Ok, explict type conversion
    sayHello(static_cast<Person>("Bob"));

    const std::string name("Evil");
    // Complication error, implicit type conversion
    // sayHello(name);
}
