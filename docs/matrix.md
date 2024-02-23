# The Matrix Class

## Construction

Matrices can be constructed in the following ways:

```c++
Matrix<int> matrix({1, 0, 0}, 
                   {0, 1, 0},
                   {0, 0, 1});

Matrix<int> empty_matrix(2, 3);
// Fills matrix with zeroes

```

## Matrix operations

The *, +, and - operators are overloaded to support their associated matrix operations. 

```c++
Matrix<int> a({1, 2, 3}
              {4, 5, 6}
              {7, 8, 9});

Matrix<int> b({1, 0, 0}
              {0, 1, 0}
              {0, 0, 1});

auto sum = a + b;
auto mult = a * b;
auto sub = a - b;

```
## Decompositions


