#pragma once

#include <vector>
#include <complex>
namespace linalg {
template <typename T> 
class SparseMatrix {
    private:
    int n_rows;
    int n_columns;
    std::vector<T> data; //excludes zeros
    std::vector<int> column_index;
    std::vector<int> row_index;

    public:
    SparseMatrix();
};
}