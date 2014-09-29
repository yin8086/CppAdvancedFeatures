#include <iostream>
#include <cstdarg>
#include <vector>
// multiple arguments in C language
double myMulsum(int n, ...)
{
    if (n < 1)
    {
        throw std::exception("Error Argument");
    }
    std::va_list ap;
    double sum = 0;
    va_start(ap, n);
    for (int i = 0; i < n; ++i)
    {
        sum += va_arg(ap, double);
    }
    va_end(ap);
    return sum;
}

// multiple arguments in Cpp11
double myMulsum(std::initializer_list<double> argList)
{
    if (argList.size() < 1)
    {
        throw std::exception("Error Argument");
    }
    double sum = 0;
    auto pBeg = argList.begin();
    for (int i = 0; i < argList.size(); ++i)
    {
        sum += pBeg[i];
    }
    
    return sum;
}


std::vector<int> returnMultiNum()
{
    int v1 = 3, v2 = 8, v3 = 4;
    return{ v1, v2, v3 };
}


int main()
{
    // 1. multiple arguments in C language
    std::cout << "1. multiple arguments in C language" << std::endl;
    double a = 3.4, b = 4.2, c = 6.5, d = 10.2;
    std::cout << a << "+" << b << "+" << c << "= " << myMulsum(3, a, b, c) << std::endl;
    std::cout << b << "+" << c << "= " << myMulsum(2, b, c) << std::endl;
    std::cout << c << "= " << myMulsum(1, c) << std::endl;
    std::cout << a << "+" << b << "+" << c << "+"
        << d << "= " << myMulsum(4, a, b, c, d) << std::endl;


    // 2. multiple arguments in Cpp language
    std::cout << "2. multiple arguments in Cpp language" << std::endl;
    std::cout << a << "+" << b << "+" << c << "= " << myMulsum({a, b, c}) << std::endl;
    std::cout << b << "+" << c << "= " << myMulsum({b, c}) << std::endl;
    std::cout << c << "= " << myMulsum({c}) << std::endl;
    std::cout << a << "+" << b << "+" << c << "+"
        << d << "= " << myMulsum({a, b, c, d}) << std::endl;
    
    //Return vector using {}
    std::cout << "Return vector using {}" << std::endl;
    auto bag = returnMultiNum();
    for (auto cE : bag)
    {
        std::cout << cE << " ";
    }
    std::cout << std::endl;
    std::cin.get();
}