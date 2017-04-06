//
// Created by marti on 06/04/2017.
//

#include "Matrix.h"

// Default constructor
template <typename Type>
Matrix<Type>::Matrix() {}

template <typename Type>
Matrix<Type>::Matrix(const int& rows, const int& cols, const Type& val) {
    for (int i = 0; i < rows; i++) {
        std::vector<Type> col_vec (cols, val);
        mat.push_back(col_vec);
    }
}

template <typename Type>
Matrix<Type>::Matrix(const Matrix<Type>& rhs) { mat = rhs.get_mat(); }

template <typename Type>
Matrix<Type> &Matrix<Type>::operator= (const Matrix<Type>& rhs) {
    if (this == &rhs) return *this;
    mat = rhs.get_mat();
    return *this;
}

template <typename Type>
std::vector<std::vector<Type> > Matrix<Type>::get_mat() const {
    return std::vector<std::vector<Type> >(mat);
}

template <typename Type>
Type& Matrix<Type>::value(const int& row, const int& col) {
    return mat[row][col];
}

template <typename Type>
Matrix<Type>::~Matrix() {}







