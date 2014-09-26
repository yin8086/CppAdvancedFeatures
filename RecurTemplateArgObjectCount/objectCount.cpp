#include <iostream>

// Counted template is a template whose size has
// no relationship with type T.
template<class T>
class Counted
{
    static int m_count;
public:
    Counted()
    {
        ++m_count;
    }
    ~Counted()
    {
        --m_count;
    }
    static int count() { return m_count; }
};

template<class T>
int Counted<T>::m_count = 0;

// Counted template is a template whose size has
// no relationship with type T, so Counted can be instantiate
class CountedObj : public Counted < CountedObj >
{

};


int main()
{
    std::cout << "Count: " << CountedObj::count() << std::endl;
    CountedObj co;
    std::cout << "Count: " << CountedObj::count() << std::endl;
    {
        CountedObj co2;
        std::cout << "Count: " << CountedObj::count() << std::endl;
    }
    std::cout << "Count: " << CountedObj::count() << std::endl;
    CountedObj co2;
    std::cout << "Count: " << CountedObj::count() << std::endl;
    std::cin.get();
}