#ifndef ASSERTTEMP
#define ASSERTTEMP

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

#endif