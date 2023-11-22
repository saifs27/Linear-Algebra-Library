#include <vector>
class Matrix {
    private:
        int rows;
        int columns;
        std::vector<float> elements;

    public:
        Matrix(int row_length, int column_length) {
            rows = row_length;
            columns = column_length;
            for (int i = 0; i < rows*columns; i++) {
                elements.push_back(0);
            }
        }

        int getRowLength() {
            return rows;
        }

        int getColumnLength() {
            return columns;
        }

        std::vector<float> getElements() {
            return elements;
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
                result.elements.push_back(elements[i] + matrix.elements[i]);
            }
            result.columns = columns;
            result.rows = rows;
            return result;
        }


};