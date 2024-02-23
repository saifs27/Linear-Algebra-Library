#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <cstdint>
#include <complex>

#include "../src/sparse.cpp"

TEST_CASE("constructor", "[Constructor]")
{
    std::vector<std::vector<int>> m = 
    {{3, 0, 0, 0, 1, 0}, 
     {0, 4, 1, 0, 5, 9},
     {0, 0, 0, 2, 0, 6},
     {5, 0, 0, 3, 0, 0},
     {0, 0, 0, 0, 5, 0},
     {0, 0, 0, 8, 9, 7}};
     linalg::Matrix<int> normalMatrix(6,6);
     normalMatrix = m;
     linalg::SparseMatrix<int> sparse(normalMatrix);
     auto values = sparse.values();
     auto cols = sparse.columns();
     auto rows = sparse.rows();

     std::vector<int> expectedValues = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7};
     std::vector<int> expectedCols =   {0, 4, 1, 2, 4, 5, 3, 5, 0, 3, 4, 3, 4, 5};
     std::vector<int> expectedRows = {0, 2, 6, 8, 10, 11, 14};
     REQUIRE (normalMatrix.n_rows == 6);
     REQUIRE (values == expectedValues);
     REQUIRE (cols == expectedCols);
     REQUIRE (rows == expectedRows);

}

