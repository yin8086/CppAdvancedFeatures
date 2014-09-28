#include <iostream>
#include "compareTemplate.h"
#include "condTemplate.h"
#include "assertTemplate.h"
#include "composeTemplate.h"
#include "interpretTemplate.h"

// @@@ Meta Programming in C++ is use different C++ features 
// to make compiler do compiling time calculations to speed up
// procedures. @@@

// The most important thing is that we can only deal with constants

// calculation can only be done in enum when at compiling time
// #define cannot, and static const cannot

//#define DO_FIB

#ifdef DO_FIB
#include "recursiveTemplate.h"
#endif // DO_FIB


int main()
{
#ifdef DO_FIB
    const int ns = 8;
    // 1. Recursive(or iterate)
    std::cout << "Fibonacci(" << ns << ") = " << Fib<ns>::val << std::endl;
#endif
    const int a = 3, b = 4;
    // 2. compare
    std::cout << "Max(" << a << ", " << b << ") = " << Max<a, b>::val << std::endl;
    // 3. Condition Test do different work
    Select<a != b> s;
    // 4. Assert
    STATIC_CHECK(a != b, not_equal);

    // 5. Calculate
    int c[] = { 1, 2, 3, 4, 5 };
    int d[] = { 2, 4, 6, 8, 10 };
    std::cout << "Dot Product: " << DotProduct<5, int>::eval((int*)c, (int *)d) << std::endl;

    double x = 3.14;
    Variable v(x);
    std::cout << "(" << x << "+" << 2 << ")*" << 3 << " = " << eval((v + 2) * 3) << std::endl;
    std::cin.get();
}