#include <iostream>

#include "matrix.h"

int main() {
    int n;
    std::cout << "Enter the size of the matrix (n): " << std::endl;
    std::cin >> n;

    lr4::Matrix<int> matrix (n, n);

    std::cout << "Enter the elements of the matrix\n"
                 "(\n"
                 "a11 a12 a13\n"
                 "a21 a22 a23\n"
                 "a31 a32 a33\n"
                 ")\n";

    std::cin >> matrix;

    if (matrix.isLatinSquare()) {
        std::cout << "The given matrix is a latin square";
    } else {
        std::cout << "The given matrix is not a latin square";
    }

    return 0;
}
