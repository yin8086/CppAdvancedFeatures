#include <iostream>
#include <bitset>
#include <iomanip>

const int BIT_NUM = 9;

int main()
{
    std::bitset<BIT_NUM> bs1("10111");
    std::cout << "Bitset<40>: " << bs1 << ", to_ulong = " << bs1.to_ullong() << std::endl;
    std::cout << "Bit 3 set? :" << std::boolalpha << bs1.test(3) << std::endl;
    bs1 = bs1.flip(3);
    std::cout << "Bitset<40> flip pos 3: " << bs1 << ", to_ulong = " << bs1.to_ullong() << std::endl;
    std::cin.get();
}