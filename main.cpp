#include <iostream>
#include <cassert>

#include "Matrix.h"

constexpr int DEFAULT_VALUE = 0;

int main()
{
    try
    {
        Matrix<int, DEFAULT_VALUE> matrix;
        assert(matrix.size() == 0); // все ячейки свободны

        for (int i = 0; i < 10; ++i)
        {
            matrix[i][i] = i;
            matrix[i][9 - i] = 9 - i;
        }

        for (int i = 1; i < 9; ++i)
        {
            for (int j = 1; j < 9; ++j)
            {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }

        std::cout << std::endl << "Busy cell count = " << matrix.size() << std::endl << std::endl;

        for (size_t i = 0; i < matrix.size(); i++)
        {
            for (size_t j = 0; j < matrix.size(); j++)
            {
                if (matrix[i][j] != DEFAULT_VALUE)
                {
                    std::cout << i << j << matrix[i][j] << std::endl;
                }
            }
        }
    }
    catch (std::exception ex)
    {
        std::cerr << ex.what() << std::endl;
    }
}
