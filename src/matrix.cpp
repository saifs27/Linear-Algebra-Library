#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

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
        
    Matrix<T>(int row_num, int column_num) {
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

    int accessElement(int row_index, int column_index) {
        return row_index * columnNum + column_index;
    }

    Matrix add(Matrix matrix) {
        Matrix result(0,0);
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

    Matrix multiply(Matrix matrix) {
        /* Since the matrix is stored in row-major order, 
        */
        Matrix result(rowNum, matrix.columnNum);
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

    Matrix transpose() {
        Matrix result(rowNum, columnNum);
        for (int i = 0; i < rowNum; i++) {
            for (int j = 0; j < columnNum; j++) {
                result.data[result.accessElement(i,j)] = data[accessElement(j,i)];
            }
        }

        return result;

    }

    T trace() {
        T result = 0;
        for (int i = 0; i < rowNum; i++) {
            result += data[accessElement(i, i)];
        }
        return result;
    }



};

template <typename U>
class Decomposition: Matrix<U> {
    private:
    typedef struct {
        Matrix<U> lower;
        Matrix<U> upper;
    } Matrices;

    public:
    Matrices LU() {

    }

    Matrices cholesky() {

    }

    Matrices LDL() {

    }

    
};



int main() {

    Matrix<int> m1(2, 2);
    Matrix<int> m2(2,2);
    m1.data[0] = 7;
    m1.data[1] = 5;
    m1.data[2] = 6;
    m1.data[3] = 3;

    m2.data[0] = 2;
    m2.data[1] = 1;
    m2.data[2] = 5;
    m2.data[3] = 1;

    Matrix m = m1.transpose();

    for (int i = 0; i < 4; i++){
    std::cout << m.data[i] << std::endl;
    }


}