#ifndef COMPTEMP
#define COMPTEMP
// compare in compiling
template<int n1, int n2>
struct Max
{
    enum { val = n1 > n2 ? n1 : n2 };
};
#endif