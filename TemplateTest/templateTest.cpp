#include <iostream>
#include <vector>
#include <deque>

template<class T, template<class> class Seq>
class TemplateAsArg
{

};

template<class T, template<class U, class Allocator = std::allocator<U> > class Seq>
class STLSeqAsArg
{
    typename Seq<T>::iterator pi;
    typedef typename Seq<T>::iterator VI;
    VI pi2;
public:
    STLSeqAsArg()
    {
        std::cout << "template version" << std::endl;
    }
};

template<class T>
class STLSeqAsArg < T, std::vector >
{
public:
    STLSeqAsArg()
    {
        std::cout << "special version" << std::endl;
    }
};


template<class T>
int myCompare(const T& lhs, const T& rhs);

template<class T>
class Complex
{
    // use template function must add <>
    friend int myCompare<>(const T& lhs, const T& rhs);

    template<class X, template<class> class Seq>
    friend class TemplateAsArg;

public:
    Complex() {}
    template<class X>
    Complex(const Complex<X>& rhs) {}

    template<class X>
    X funchaha();
};

template<class T>
template<class X>
X Complex<T>::funchaha()
{
    return X();
}

template<class T>
int myCompare(const T& lhs, const T& rhs)
{
    std::cout << "template MyCompare" << std::endl;
    return 0;
}

template<>
int myCompare<const char*>(const char* const& lhs, const char* const& rhs)
{
    std::cout << "special MyCompare" << std::endl;
    return 0;
}

int main()
{
    STLSeqAsArg<int, std::deque> ss;
    // can not omit argument, but when the argument fits the special
    // version, the special version will be activated
    STLSeqAsArg<float, std::vector> s2;
    Complex<int> ci;
    ci.funchaha<float>();
    myCompare(3, 5);
    char *str1 = "nihao";
    char *str2 = "byebye";
    myCompare(const_cast<const char*>(str1), const_cast<const char*>(str2));
    std::cin.get();
}