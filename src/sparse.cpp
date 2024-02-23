#include "../include/linalg/sparse.hpp"
namespace linalg {



template <typename T>
SparseMatrix<T>::SparseMatrix(Matrix<T> matrix)
{
    auto colSize = matrix.n_columns;
    auto rowSize = matrix.n_rows;
    int matrixSize = matrix.size();

    int offset = 0;
    push_row(0);
    for (int row = 0; row < rowSize; row++)
    {
        

        for (int column = 0; column < colSize; column++)
        {
            auto val = matrix.at(row, column);
            if (val != 0)
            {
                offset += 1;
                push_value(val);
                push_column(column);

            }
        }

        push_row(offset);

    }





}











}