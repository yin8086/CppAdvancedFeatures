#include <iostream>
#include <sstream>


int main()
{
    // stringstream split element not based on space
    // but the request data types in ">>"

    //std::istringstream s("47 1.414");
    //std::istringstream s("1.414");
    std::istringstream s("47 1.414 this is go");
    int i;
    float f;
    s >> i >> f;
    std::cout <<"i " << i << " f: " << f << std::endl;
    // use rdbuf()
    std::cout << "Left: " << s.rdbuf() << std::endl;
    
    std::ostringstream os;
    int k = 4, j = 5;
    float m = 3.44;
    os << k << " " << j << " " << m;
    std::cout << os.str() << std::endl;
    std::cin.get();

}