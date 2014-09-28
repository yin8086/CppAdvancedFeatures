#ifndef COMPOSETEMPLATE
#define COMPOSETEMPLATE
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
#endif