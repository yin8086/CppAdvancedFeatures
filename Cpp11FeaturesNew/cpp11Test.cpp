#include <iostream>
#include <string>
#include <cctype>
#include <vector>

// function using trailing return;
int odd[] = { 1, 3, 5, 7, 9 };
auto func1(int i) -> int(*)[5]
{
    return &odd;
}
decltype(&odd) func2(int i)
{
    return &odd;
}


// default ctor
class TestCtor
{
    TestCtor() = default;
    // in-class initialize
    std::vector<int> m_vi{ 1, 2, 3 };
};

int main()
{
    // new type
    char16_t ws = 'f';
    char32_t ww = 'w';

    // initializer list
    int abc{ 0 };
    // nullptr
    int *p1 = nullptr;

    std::cout << "ws=" << ws << ", ww=" << ww << ", abc=" << abc << std::endl;

    // same as typede int WS;
    using WS = int;
    WS b = 0;

    // auto 
    auto di = 34;
    auto pi = 3.14;
    
    auto &ri = di;

    // decltype, get type from expression
    decltype(pi * 5) newPi = 3.2;

    std::cout << "b" << b << ", di=" << di << ", pi=" 
        << pi << ", ri=" << ri << ", newPi=" << newPi;


    // new for statement
    std::string testStr("NihaoCpp");
    std::cout << testStr << std::endl;
    for (auto c : testStr)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;
    for (auto &c : testStr)
    {
        if (std::isalpha(c))
        {
            c = std::toupper(c);
        }
    }
    std::cout << testStr << std::endl;

    // initializer list for containers
    std::vector<std::string> arc{ "nihao", "zaijian", "byebye" };
    // the same as
    // std::vector<std::string> arc = { "nihao", "zaijian", "byebye" };
    // '=' can be omitted
    for (auto str : arc)
    {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    // general begin and end method that return the  begin and end iterator
    int ia[] = { 0, 1, 2, 3, 4, 5 };
    int *int_beg = std::begin(ia);
    int *int_end = std::end(ia);

    int *p = int_beg;
    while (p != int_end)
    {
        std::cout << *p++ << " ";
    }

    // initializer_list<int> usage in argument and return value, see ValArgInC


    std::cin.get();
}