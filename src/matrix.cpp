#include "../include/linalg/matrix.hpp"
namespace linalg {
template <class T>
Matrix<T>::Matrix(int row_num, int column_num)
    : n_rows(row_num), n_columns(column_num) {
    for (int key = 0; key < n_rows * n_columns; key++) {
        data.push_back((T)0);
        Indices i;
        i.rowIndex = (key / (column_num));
        i.columnIndex = key % column_num;
    }    
}




template <typename T>
T Matrix<T>::at(int row_index, int column_index) {
    return data[row_index * n_columns + column_index];
}

template <typename T>
T Matrix<T>::access(int row_index, int column_index) {
    return row_index * n_columns + column_index;
}


template <typename T>
void Matrix<T>::print() {
    
}

template <typename T>
Matrix<T> Matrix<T>::operator=(std::vector<std::vector<T>> m){  
    int n_rows = m.size();
    int n_columns = (m[0]).size();
    Matrix<T> result(n_rows, n_columns);

    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_columns; j++) {
            result.data.push_back(m[i][j]);
        }
    }
    return result;
}


template <typename T>
Matrix<T> Matrix<T>::operator+(Matrix matrix){
    Matrix<T> result(0,0);
    for (int i = 0; i < n_columns * n_rows; i++) {
        result.data.push_back(data[i] + matrix.data[i]);
    }
    result.n_columns = n_columns;
    result.n_rows = n_rows;
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(Matrix matrix){
    Matrix<T> result(0,0);
    for (int i = 0; i < n_columns * n_rows; i++) {
        result.data.push_back(data[i] - matrix.data[i]);
    }
    result.n_columns = n_columns;
    result.n_rows = n_rows;
    return result;
}


template <typename T>
Matrix<T> Matrix<T>::operator*(Matrix matrix) {
    /* Since the matrix is stored in row-major order, 
    */
    Matrix<T> result(n_rows, matrix.n_columns);
    if (n_columns != matrix.n_rows) {return result;}
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < matrix.n_columns; j++) {
            auto sum = 0;
            for (int k = 0; k < n_columns; k++) {
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
    Matrix<T> result(n_rows, n_columns);
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_columns; j++) {
            result.data[access(i, j)] = at(j, i);
        }
    }
    return result;
    }

template <typename T>
Matrix<T> Matrix<T>::ctranspose() {
    Matrix<T> result(n_rows, n_columns);
    
}

template <typename T>
T Matrix<T>::trace() {
    T result = 0;
    for (int i = 0; i < n_rows; i++) {
        result += at(i, i);
    }
    return result;
}

template <typename T>
int Matrix<T>::rank(){
    int result = 0;
    
}


template <typename T>
std::tuple<Matrix<T>, Matrix<T>> Matrix<T>::lu() {
    Matrix<T> L(n_rows, n_columns);
    Matrix<T> U(n_rows, n_columns);

    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_rows; j++) {
            if (i >= j) {
    
            }
        }
    }

}

template <typename T>
Matrix<T> Matrix<T>::cholesky() {
    Matrix<T> L(n_rows, n_columns);
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
    if (n_rows == n_columns) { return true;}
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
    Matrix<std::complex<T>> complex_conjugate(n_rows, n_columns);
    Matrix<std::complex<T>> result(n_rows, n_columns);
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
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_columns; j++) {
            
        }
    }
}

template <typename T>
bool Matrix<T>::isVector(){
    if (n_columns == 0) {return true;}
    return false;
}
}

    



