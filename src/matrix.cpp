#include <vector>
#include <unordered_map>
#include <iostream>

template <typename T>
class Matrix {
    private:
        int rows;
        int columns;
        std::vector<T> data;

        typedef struct {
            Matrix<T> lower;
            Matrix<T> upper;
        } Matrices;

        typedef struct {
            int row;
            int column;
        } Indices;

    public:
        std::unordered_map<int, Indices> indices;
        
        Matrix<T>(int row_num, int column_num) {
            rows = row_num;
            columns = column_num;
            for (int index = 0; index < rows*columns; index++) {
                data.push_back(0);
                Indices i;
                i.row = (index / (column_num));
                i.column = index % column_num;
                indices[index] = i;
            }
        }

        int getRowLength() {
            return rows;
        }

        int getColumnLength() {
            return columns;
        }

        std::vector<float> getElements() {
            return data;
        }

        void setRowLength() {

        }

        void insert(int row_index, int column_index) {

        }

        Matrix add(Matrix matrix) {
            Matrix result(0,0);
            if ((columns != matrix.columns) || (rows != matrix.rows)){
                return matrix;
            }
            for (int i = 0; i < columns * rows; i++) {
                result.data.push_back(data[i] + matrix.data[i]);
            }
            result.columns = columns;
            result.rows = rows;
            return result;
        }



        Matrix multiply(Matrix matrix) {
            
        }

        Matrices LU_Decomposition(Matrix m) {
            
        }

};



int main() {

    Matrix<int> m(3, 2);


    for (int i = 0; i < 6; i++){
        int element = i;
        int x = m.indices[element].row;
        int y = m.indices[element].column;

        std::cout << "element: " << element << "\n";
        std::cout << "row: " << x << "\n";
        std::cout << "column: " << y << "\n\n";        
    }



}