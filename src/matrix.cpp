#include <iostream>
#include "../include/linalg/matrix.hpp"

template <class T>
Matrix<T>::Matrix(int row_num, int column_num){
    rowNum = row_num;
    columnNum = column_num;
    for (int key = 0; key < rowNum*columnNum; key++) {
        data.push_back(0);
        Indices i;
        i.rowIndex = (key / (column_num));
        i.columnIndex = key % column_num;
        indices_map[key] = i;
    }    
}

template <typename T>
int Matrix<T>::accessElement(int row_index, int column_index) {
    return row_index * columnNum + column_index;
    }

template <typename T>
Matrix<T> Matrix<T>::add(Matrix matrix) {
    Matrix<T> result(0,0);
    if ((columnNum != matrix.columnNum) || (rowNum != matrix.rowNum)){
        return matrix;
    }
    for (int i = 0; i < columnNum * rowNum; i++) {
        result.data.push_back(data[i] + matrix.data[i]);
    }
    result.columnNum = columnNum;
    result.rowNum = rowNum;
    return result;
    }

template <typename T>
Matrix<T> Matrix<T>::multiply(Matrix matrix) {
    /* Since the matrix is stored in row-major order, 
    */
    Matrix<T> result(rowNum, matrix.columnNum);
    if (columnNum != matrix.rowNum) {return result;}
    for (int i = 0; i < rowNum; i++) {
        for (int j = 0; j < matrix.columnNum; j++) {
            auto sum = 0;
            for (int k = 0; k < columnNum; k++) {
                auto A_ik = data[accessElement(i, k)];
                auto B_kj = matrix.data[matrix.accessElement(k, j)];
                sum += A_ik * B_kj;
            }
            result.data[result.accessElement(i, j)] = sum;
        }
    }
    return result;
    }

template <typename T>
T Matrix<T>::determinant() {

}

template <typename T>
Matrix<T> Matrix<T>::transpose() {
    Matrix<T> result(rowNum, columnNum);
    for (int i = 0; i < rowNum; i++) {
        for (int j = 0; j < columnNum; j++) {
            result.data[result.accessElement(i,j)] = data[accessElement(j,i)];
        }
    }
    return result;
    }

template <typename T>
T Matrix<T>::trace() {
    T result = 0;
    for (int i = 0; i < rowNum; i++) {
        result += data[accessElement(i, i)];
    }
    return result;
}


template <typename T>
std::tuple<Matrix<T>, Matrix<T>> Matrix<T>::LU() {
}

template <typename T>
std::tuple<Matrix<T>, Matrix<T>> cholesky() {

}

template <typename T>
std::tuple<Matrix<T>, Matrix<T>> LDL() {

}
template <typename T>
std::tuple<Matrix<T>, Matrix<T>> SVD() {

}



