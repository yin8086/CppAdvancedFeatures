#include <iostream>

// @@@ Meta Programming in C++ is use different C++ features 
// to make compiler do compiling time calculations to speed up
// procedures. @@@

// The most important thing is that we can only deal with constants

// calculation can only be done in enum when at compiling time
// #define cannot, and static const cannot


// recursive in compiling
template<int n>
struct Fib
{
    enum { val = Fib<n-1>::val + Fib<n-2>::val };
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

// compare in compiling
template<int n1, int n2>
struct Max
{
    enum {val = n1 > n2 ? n1 : n2};
};

// Condition Implement in compiling
template<bool cond>
class Select
{
    // implement 1
public:
    Select()
    {
        std::cout << "cond false implement" << std::endl;
    }
};

template<>
class Select<true>
{
    // implement 2
public:
    Select()
    {
        std::cout << "cond true implement" << std::endl;
    }
};


// Assert in compiling
template<bool cond>
class StaticCheck
{
public:
    StaticCheck(...) {}
};


// when false type StaticCheck is not a complete TYPE
// so will print error
template<>
class StaticCheck < false >
{};

#define STATIC_CHECK(expr, msg) {\
    class Error_## msg { }; \
    Error_## msg f;\
    sizeof(StaticCheck<expr>(f));\
}


template <size_t N, typename T>
class DotProduct
{
public:
    static T eval(T* a, T* b)
    {
        return  DotProduct<1, T>::eval(a, b) + DotProduct<N - 1, T>::eval(a + 1, b + 1);
    }
};

template <typename T>
class DotProduct < 1, T >
{
public:
    static T eval(T* a, T* b)
    {
        return (*a)*(*b);
    }
};






class Literal
{
public:
    Literal(const double v) : _val(v)
    {}

    double eval() const
    {
        return _val;
    }

private:
    const double _val;
};

class Variable
{
public:
    Variable(double& v) : _val(v)
    {}

    double eval() const
    {
        return _val;
    }

private:
    double& _val;
};

template <typename ExprT1, typename ExprT2, typename BinOp>
class BinaryExpr
{
public:
    BinaryExpr(ExprT1 e1, ExprT2 e2, BinOp op = BinOp()) :
        _expr1(e1), _expr2(e2), _op(op)
    {}

    double eval() const
    {
        return _op(_expr1.eval(), _expr2.eval());
    }

private:
    ExprT1 _expr1;
    ExprT2 _expr2;
    BinOp  _op;
};

/*
template <typename ExprT1, typename ExprT2>
BinaryExpr<ExprT1, ExprT2, std::plus<double>> operator+(ExprT1 e1, ExprT2 e2)
{
    return BinaryExpr<ExprT1, ExprT2, std::plus<double>>(e1, e2);
}
*/

int main()
{
    const int ns = 8;
    // 1. Recursive(or iterate)
    std::cout << "Fibonacci(" << ns << ") = " << Fib<ns>::val << std::endl;
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


    std::cin.get();
}