#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "../include/linalg/matrix.hpp"

TEST_CASE("access element", "[Matrix::accessElement]") {
    REQUIRE (Matrix<int>::accessElement(0,0) == 2);
}

