#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <cstdint>


#include "../src/matrix.cpp"




TEST_CASE("matrix", "[Matrix::accessElement]") {
    Matrix<int> m1(2,2);
    m1.data[0] = 1;
    m1.data[1] = 4;
    m1.data[2] = 3;
    m1.data[3] = 7;
    
    REQUIRE (m1.accessElement(0,0) == 0);
    REQUIRE (m1.trace() == 8);
}

