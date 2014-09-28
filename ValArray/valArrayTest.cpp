#include <iostream>
#include <valarray>
#include <iomanip>

// do batch work for multi-elements, like plus, minus...
template<class T>
class Matrix {
    size_t m_Rows;
    size_t m_Cols;
    std::valarray<T> data;
public:
    Matrix(int r, int c) : m_Rows(r), m_Cols(c), data(r*c) {}
    int& operator()(int r, int c) { return data[r*m_Cols + c]; }

    // std::slice(startPos, size, stride)
    // get [size] number of elements
    // from pos:
    // startPos + 0*(stride)   ... startPos + (size-1)*(stride)

    // std::gslice(startPos, valarray<size_t> sizeSets, valarray<size_t> strideSets)
    // startPos
    // sizeSets {2, 3},   strideSets { 4, 6}
    // elements from different pair of size and stride
    // the same as 
    // slice(startPos, sizeSets[0], strideSet[0]);  and
    // slice(startPos, sizeSets[1], strideSet[1]);

    int colSum(int c) const {
        return data[std::slice(c, m_Rows, m_Cols)].sum();
    }
    int rowSum(int r) const {
        return data[std::slice(r*m_Cols, m_Cols, 1)].sum();
    }


    friend std::ostream& operator<<(std::ostream& out, const Matrix<T> &rhs)
    {
        for (size_t r = 0; r < rhs.m_Rows; ++r)
        {
            for (size_t c = 0; c < rhs.m_Cols; ++c)
            {
                out << std::setw(3) << rhs.data[r*rhs.m_Cols + c];
                out << (c + 1 != rhs.m_Cols ? " " : "\n");
            }
        }
        return out;
    }
};


int main()
{
    Matrix<int> m(4, 3);
    int n = 0;
    for (int r = 0; r < 4; ++r)
        for (int c = 0; c < 3; ++c)
            m(r, c) = ++n;
    std::cout << m;
    int r = 2, c = 3;
    std::cout << "Row [" << r << "] Sum = " << m.rowSum(r-1) << std::endl;
    std::cout << "Col [" << c << "] Sum = " << m.colSum(c-1) << std::endl;
    std::cin.get();
}