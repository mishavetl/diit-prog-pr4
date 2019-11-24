#include <sstream>

#include "matrix.h"
#include "catch.hpp"

using namespace lr4;

TEST_CASE("Matrix class works properly", "[matrix]") {
    SECTION("isLatinSquare works properly with n = 2 (1)") {
        Matrix<int> matrix (2, 2);
        std::stringstream ss(""
                              "2 1\n"
                              "1 2\n");
        ss >> matrix;
        REQUIRE(matrix.isLatinSquare());
    }

    SECTION("isLatinSquare works properly with n = 2 (2)") {
        Matrix<int> matrix (2, 2);
        std::stringstream ss(""
                             "2 2\n"
                             "1 2\n");
        ss >> matrix;
        REQUIRE(!matrix.isLatinSquare());
    }

    SECTION("isLatinSquare works properly with n = 2 (3)") {
        Matrix<int> matrix (2, 2);
        std::stringstream ss(""
                             "2 3\n"
                             "1 2\n");
        ss >> matrix;
        REQUIRE(!matrix.isLatinSquare());
    }

    SECTION("isLatinSquare works properly with n = 3 (1)") {
        Matrix<int> matrix (3, 3);
        std::stringstream ss(""
                             "1 2 3\n"
                             "3 1 2\n"
                             "2 3 1\n");
        ss >> matrix;
        REQUIRE(matrix.isLatinSquare());
    }

    SECTION("isLatinSquare works properly with n = 3 (2)") {
        Matrix<int> matrix (3, 3);
        std::stringstream ss(""
                             "1 2 3\n"
                             "3 1 1\n"
                             "2 3 2\n");
        ss >> matrix;
        REQUIRE(!matrix.isLatinSquare());
    }

    SECTION("isLatinSquare works properly with n = 3 (2)") {
        Matrix<int> matrix (3, 2);
        std::stringstream ss(""
                             "1 2 3\n"
                             "3 1 2\n");
        ss >> matrix;
        REQUIRE(!matrix.isLatinSquare());
    }
}