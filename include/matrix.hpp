#pragma once
#include <vector>
#include <unordered_map>
#include <tuple>

template <typename T> class Matrix { 
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

    int accessElement(int row_index, int column_index);

    Matrix<T> add(Matrix matrix);
    Matrix<T> multiply(Matrix matrix);



    // decompositions
    std::tuple<Matrix<T>, Matrix<T>> LU();
    std::tuple<Matrix<T>, Matrix<T>> cholesky();
    std::tuple<Matrix<T>, Matrix<T>> LDL();
    std::tuple<Matrix<T>, Matrix<T>> SVD();


    T determinant();
    Matrix<T> transpose();
    T trace();

};