#pragma once
#include <vector>
#include <tuple>
#include <complex>
#include <cmath>


template <typename T> 
class Matrix { 
    private:
    typedef struct {
        int rowIndex;
        int columnIndex;
    } Indices;
    
    public:
    int n_rows;
    int n_columns;
    std::vector<T> data;

    Matrix(int row_num, int column_num);


    T at(int row_index, int column_index);
    T access(int row_index, int column_index);
    void print();


    Matrix<T> operator=(std::vector<std::vector<T>> m);
    Matrix<T> operator+(Matrix matrix);
    Matrix<T> operator-(Matrix matrix);
    Matrix<T> operator*(Matrix matrix);

    // decompositions
    std::tuple<Matrix<T>, Matrix<T>> lu();
    Matrix<T> cholesky();
    std::tuple<Matrix<T>, Matrix<T>> ldl();
    std::tuple<Matrix<T>, Matrix<T>> svd();


    T determinant();
    Matrix<T> transpose();
    Matrix<T> ctranspose(); // complex conjugate transpose
    T trace();
    int rank();
    T eigenvalues();
    std::vector<T> eigenvectors();

    Matrix<T> triangularLower();
    Matrix<T> triangularUpper();

    bool isSquare();
    bool isSymmetric();
    bool isHermitian();
    bool isDiagonalMatrix();
    bool isVector();
};