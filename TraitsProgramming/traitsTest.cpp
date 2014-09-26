#include <string>
#include <iostream>
#include <limits>
#include <cctype>

struct ci_char_traits : public std::char_traits < char > {
    static bool eq(char c1, char c2) {
        return std::toupper(c1) == std::toupper(c2);
    }
    static bool lt(char c1, char c2) {
        return std::toupper(c1) < std::toupper(c2);
    }
    static int compare(const char* s1, const char* s2, size_t n) {
        while (n-- != 0) {
            if (std::toupper(*s1) < std::toupper(*s2)) return -1;
            if (std::toupper(*s1) > std::toupper(*s2)) return 1;
            ++s1; ++s2;
        }
        return 0;
    }
    static const char* find(const char* s, int n, char a) {
        auto const ua(std::toupper(a));
        while (n-- != 0)
        {
            if (std::toupper(*s) == ua)
                return s;
            s++;
        }
        return nullptr;
    }
};

typedef std::basic_string<char, ci_char_traits> ci_string;

std::ostream& operator<<(std::ostream& os, const ci_string& str) {
    return os.write(str.data(), str.size());
}


void testLimits()
{
    std::cout << "[int] limits:" << std::endl;
    std::cout << "Min: " << std::numeric_limits<int>::min()
        << " Max: " << std::numeric_limits<int>::max() << std::endl;

    std::cout << "[short] limits:" << std::endl;
    std::cout << "Min: " << std::numeric_limits<short>::min()
        << " Max: " << std::numeric_limits<short>::max() << std::endl;

    std::cout << "[long long] limits:" << std::endl;
    std::cout << "Min: " << std::numeric_limits<long long>::min()
        << " Max: " << std::numeric_limits<long long>::max() << std::endl;
}

void testCharTraits()
{
    ci_string s1 = "Hello";
    ci_string s2 = "heLLo";
    if (s1 == s2)
        std::cout << s1 << " and " << s2 << " are equal\n";
}

int main()
{
    // traits class members are all
    // static constants or static member functions
    // which provide a unified interface for different type
    // so when use template programming, we could not worry about the 
    // difference of the same operation on different types, and only use the
    // traits<TYPE>::op to deal with the TYPE
    testLimits();
    testCharTraits();
    std::cin.get();
}