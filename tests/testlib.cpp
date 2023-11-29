#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>

#include "../src/matrix.cpp"


Matrix<int> m(2,2);

TEST_CASE("access element", "[Matrix::accessElement]") {
    REQUIRE (m.accessElement(0,0) == 2);
}

