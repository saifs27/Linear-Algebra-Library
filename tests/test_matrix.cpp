#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <cstdint>
#include <complex>

#include "../src/matrix.cpp"


TEST_CASE("matrix", "[Matrix]") {
    Matrix<int> m1(2,2);
    Matrix<int> m2(2,2);


    m1 = {{1, 4}, {3, 7}};
    m2 = {{2, 3}, {5, 6}};
    Matrix<int> m3 = m1 + m2;

    Matrix<int> m4(3,2);
    m4 = {{1,2}, {2,3}, {3,6}};

    Matrix<int> m5 = m4 + m4;
    
    REQUIRE (m1.at(0,0) == 1);
    REQUIRE (m1.trace() == 8);
    REQUIRE (m3.at(0,0) == 3);
    REQUIRE (m3.at(0,1) == 7);
    REQUIRE (m3.at(1,0) == 8);
    REQUIRE (m3.at(1,1) == 13);
    REQUIRE (m5.at(1,0) == 4);
}

TEST_CASE("matrixType", "[Matrix]") {
    Matrix<int> square(5,5);
    Matrix<int> notSquare(3,7);

    Matrix<int> sym(3,3);
    Matrix<std::complex<double>> herm(3,3);


    sym = {{1, 1, -1},
           {1, 2, 0}, 
           {-1, 0, 5}};

    herm.data[0] = std::complex<double>(1, 0);
    herm.data[1] = std::complex<double>(1, 1);
    herm.data[2] = std::complex<double>(4, -5);
    herm.data[3] = std::complex<double>(1, -1);
    herm.data[4] = std::complex<double>(3, 0);
    herm.data[5] = std::complex<double>(0, 3);
    herm.data[6] = std::complex<double>(4, 5);
    herm.data[7] = std::complex<double>(0, -3);
    herm.data[8] = std::complex<double>(-2, 0);

    

    Matrix<std::complex<double>> add = herm + herm;

    REQUIRE (square.isSquare() == true);
    REQUIRE (notSquare.isSquare() == false);
    REQUIRE (sym.isSymmetric() == true);
    REQUIRE (add.data[2].imag() == -10.0);
}

