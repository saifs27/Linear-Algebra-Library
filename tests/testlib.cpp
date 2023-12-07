#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <cstdint>
#include <complex>

#include "../src/matrix.cpp"

TEST_CASE("matrix", "[Matrix]") {
    Matrix<int> m1(2,2);
    Matrix<int> m2(2,2);
    m1.data[0] = 1;
    m1.data[1] = 4;
    m1.data[2] = 3;
    m1.data[3] = 7;

    m2.data[0] = 2;
    m2.data[1] = 3;
    m2.data[2] = 5;
    m2.data[3] = 6;

    Matrix<int> m3 = m1 + m2;
    
    REQUIRE (m1.data[m1.access(0,0)] == 1);
    REQUIRE (m1.trace() == 8);
    REQUIRE (m3.data[m3.access(0,0)] == 3);
    REQUIRE (m3.data[m3.access(0,1)] == 7);
    REQUIRE (m3.data[m3.access(1,0)] == 8);
    REQUIRE (m3.data[m3.access(1,1)] == 13);
}

TEST_CASE("matrixType", "[Matrix]") {
    Matrix<int> square(5,5);
    Matrix<int> notSquare(3,7);

    Matrix<int> sym(3,3);

    sym.data[0] = 1;
    sym.data[1] = 1;
    sym.data[2] = -1;
    sym.data[3] = 1;
    sym.data[4] = 2;
    sym.data[5] = 0;
    sym.data[6] = -1;
    sym.data[7] = 0;
    sym.data[8] = 5;

    REQUIRE (square.isSquare() == true);
    REQUIRE (notSquare.isSquare() == false);
    REQUIRE (sym.isSymmetric() == true);
    REQUIRE (sym.isHermitian() == true);
}

