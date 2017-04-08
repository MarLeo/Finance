//
// Created by marti on 06/04/2017.
//
#ifndef FINANCE_MATRIX_CPP
#define FINANCE_MATRIX_CPP

#include "Matrix.h"

// Default constructor
template <typename Type>
Matrix<Type>::Matrix() {}

// Constructor with row/col specification and default values
template <typename Type>
Matrix<Type>::Matrix(const int& rows, const int& cols, const Type& val) {
    for (int i = 0; i < rows; i++) {
        std::vector<Type> col_vec (cols, val);
        mat.push_back(col_vec);
    }
}

// copy constructor
template <typename Type>
Matrix<Type>::Matrix(const Matrix<Type>& rhs) { mat = rhs.get_mat(); }

// overloaded assignment operator
template <typename Type>
Matrix<Type> &Matrix<Type>::operator= (const Matrix<Type>& rhs) {
    if (this == &rhs) return *this;
    mat = rhs.get_mat();
    return *this;
}

template <typename Type>
std::vector<std::vector<Type>> Matrix<Type>::get_mat() const {
    return std::vector<std::vector<Type> >(mat);
}

template <typename Type>
Type& Matrix<Type>::value(const int& row, const int& col) {
    return mat[row][col];
}

template <typename Type>
Matrix<Type>::~Matrix() {}

template <typename Type>
unsigned Matrix<Type>::row() const {
    return mat.size();
}

template <typename Type>
unsigned Matrix<Type>::col() const {
    return mat.size();
}

#endif






