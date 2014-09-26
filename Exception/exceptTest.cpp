#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <exception>

const int BUFSIZE = 100;

class MyExcept :public std::exception
{
    char errStr[BUFSIZE];
public:
    MyExcept(const char* src)
    {
        std::strcpy(errStr, src);
    }
    virtual const char *what() const {
        return errStr;
    }
};

class Base
{
    int a;
public:
    Base(int d) :a(d) 
    {
        throw MyExcept("Base Except");
    }
};

class Derived :public Base
{
public:
    Derived(int d) try :Base(d)
    {
        std::cout << "Haha" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
};

int main() try
{
    try
    {
        std::cout << "Hello" << std::endl;
        Derived d(3);
        throw MyExcept("Main Except");
    }
    catch (const std::exception& me)
    {
        std::cerr << me.what() << std::endl;
    }
    std::cin.get();
}
catch (...)
{
    std::cerr << "Function level catch" << std::endl;
}