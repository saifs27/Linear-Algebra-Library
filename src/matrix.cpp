#include "../include/linalg/matrix.hpp"

template <class T>
Matrix<T>::Matrix(int row_num, int column_num){
    rowNum = row_num;
    columnNum = column_num;
    for (int key = 0; key < rowNum*columnNum; key++) {
        data.push_back((T)0);
        Indices i;
        i.rowIndex = (key / (column_num));
        i.columnIndex = key % column_num;
        indices_map[key] = i;
    }    
}




template <typename T>
T Matrix<T>::at(int row_index, int column_index) {
    return data[row_index * columnNum + column_index];
}

template <typename T>
T Matrix<T>::access(int row_index, int column_index) {
    return row_index * columnNum + column_index;
}


template <typename T>
void Matrix<T>::print() {
    
}

template <typename T>
void Matrix<T>::operator=(std::vector<std::vector<T>> m){
    data.clear();
    rowNum = m.size();
    columnNum = (m[0]).size();
    for (int i = 0; i < rowNum; i++) {
        for (int j = 0; j < columnNum; j++) {
            data.push_back(m[i][j]);
        }
    }
}


template <typename T>
Matrix<T> Matrix<T>::operator+(Matrix matrix){
    Matrix<T> result(0,0);
    for (int i = 0; i < columnNum * rowNum; i++) {
        result.data.push_back(data[i] + matrix.data[i]);
    }
    result.columnNum = columnNum;
    result.rowNum = rowNum;
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(Matrix matrix){
    Matrix<T> result(0,0);
    for (int i = 0; i < columnNum * rowNum; i++) {
        result.data.push_back(data[i] - matrix.data[i]);
    }
    result.columnNum = columnNum;
    result.rowNum = rowNum;
    return result;
}


template <typename T>
Matrix<T> Matrix<T>::operator*(Matrix matrix) {
    /* Since the matrix is stored in row-major order, 
    */
    Matrix<T> result(rowNum, matrix.columnNum);
    if (columnNum != matrix.rowNum) {return result;}
    for (int i = 0; i < rowNum; i++) {
        for (int j = 0; j < matrix.columnNum; j++) {
            auto sum = 0;
            for (int k = 0; k < columnNum; k++) {
                auto A_ik = at(i, k);
                auto B_kj = matrix.at(k, j);
                sum += A_ik * B_kj;
            }
            result.data[access(i, j)] = sum;
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
            result.data[access(i, j)] = at(j, i);
        }
    }
    return result;
    }

template <typename T>
T Matrix<T>::trace() {
    T result = 0;
    for (int i = 0; i < rowNum; i++) {
        result += at(i, i);
    }
    return result;
}


template <typename T>
std::tuple<Matrix<T>, Matrix<T>> Matrix<T>::lu() {
    Matrix<T> L(rowNum, columnNum);
    Matrix<T> U(rowNum, columnNum);

    for (int i = 0; i < rowNum; i++) {
        for (int j = 0; j < rowNum; j++) {
            if (i >= j) {
    
            }
        }
    }

}

template <typename T>
Matrix<T> Matrix<T>::cholesky() {
    Matrix<T> L(rowNum, columnNum);
    int matrix_size = data.size();
    for (int i = 0; i  < matrix_size; i++) {
        for (int j = 0; j < i; j++) {
            auto sum = 0;
            for (int k = 0; k < j; k++) {
                sum += L.at(i, k) * L.at(j, k);
            }
            if (i == j) {
                L.data[access(i, j)] = sqrt(at(i, j) - sum);
            }
            else {
                L.data[access(i, j)] = (1.0 / L.at(j, j) * (at(i, j) - sum)); 
            }
        }
    }

    return L;

}

template <typename T>
std::tuple<Matrix<T>, Matrix<T>> Matrix<T>::ldl() {

}
template <typename T>
std::tuple<Matrix<T>, Matrix<T>> Matrix<T>::svd() {

}

template <typename T>
bool Matrix<T>::isSquare(){
    if (rowNum == columnNum) { return true;}
    return false;
}
template <typename T>
bool Matrix<T>::isSymmetric(){
    Matrix<T> t = transpose();
    if (data == t.data) {return true;}
    return false;
}


template <typename T>
bool Matrix<T>::isHermitian(){
    if (typeid(T) != typeid(std::complex<double>)) {
        return isSymmetric();
    }
    Matrix<std::complex<T>> complex_conjugate(rowNum, columnNum);
    Matrix<std::complex<T>> result(rowNum, columnNum);
    std::complex<T> element;
    for (int i = 0; i < data.size(); i++) {
        element = data[i];
        complex_conjugate.data[i] = element.real() - element.imag();
    }

    result = complex_conjugate.transpose();

    if (data == result.data) {return true;}
    return false;
}

template <typename T>
bool Matrix<T>::isDiagonalMatrix(){

}

template <typename T>
bool Matrix<T>::isVector(){

}

    



