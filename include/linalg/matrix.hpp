#pragma once
#include <vector>
#include <unordered_map>
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
    int rowNum;
    int columnNum;
    std::vector<T> data;
    
    std::unordered_map<int, Indices> indices_map;

    Matrix(int row_num, int column_num);


    T at(int row_index, int column_index);
    T access(int row_index, int column_index);
    void print();


   void operator=(std::vector<std::vector<T>> m);
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
    T trace();

    bool isSquare();
    bool isSymmetric();
    bool isHermitian();
    bool isDiagonalMatrix();
    bool isVector();



};