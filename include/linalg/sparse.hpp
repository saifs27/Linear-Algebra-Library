#pragma once

#include <vector>
#include <complex>
#include "matrix.hpp"

namespace linalg {
template <typename T> 
class SparseMatrix {

    // use Compressed Sparse Row (CSR) representation
    private:
    std::vector<T> _rows = {};
    std::vector<T> _columns = {};
    std::vector<T> _values = {};

    public:
    //SparseMatrix(std::vector<T> rows, std::vector<T> columns, std::vector<T> values)
    //: _rows(rows), _columns(columns), _values(values) {};
    SparseMatrix(Matrix<T> matrix);

    void push_value(T value) {if (value != 0) _values.push_back(value);};
    void push_column(int column) {_columns.push_back(column);};
    void push_row(int row) {_rows.push_back(row);};

    void pop_value() { _values.pop_back();};
    void pop_column() {_columns.pop_back();};
    void pop_row() {_rows.pop_back();};

    std::vector<T> rows() const {return _rows;};
    std::vector<T> columns() const {return _columns;};
    std::vector<T> values() const {return _values;};
};
}