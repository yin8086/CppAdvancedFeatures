#ifndef CONDTEMP
#define CONDTEMP
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
class Select < true >
{
    // implement 2
public:
    Select()
    {
        std::cout << "cond true implement" << std::endl;
    }
};

#endif