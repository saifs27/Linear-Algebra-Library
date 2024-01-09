#include "matrix.hpp"

template <typename T>
class Vector {
    public:
    int size;
    std::vector<T> data;
    Vector(int size);
    T dot(Vector vec);
    Vector cross(Vector vec);
    

    Matrix<T> operator=(std::vector<T> m);
    Matrix<T> operator+(Matrix matrix);
    Matrix<T> operator-(Matrix matrix);


};