#ifndef RECURTEMP
#define RECURTEMP
// recursive in compiling
template<int fibn>
struct Fib
{
    enum { val = Fib<fibn - 1>::val + Fib<fibn - 2>::val };
};

template<>
struct Fib < 0 >
{
    enum { val = 0 };
};

template<>
struct Fib < 1 >
{
    enum { val = 1 };
};

#endif // !RECURTEMP

