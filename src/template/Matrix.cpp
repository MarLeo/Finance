//
// Created by marti on 06/04/2017.
//
#ifndef FINANCE_MATRIX_CPP
#define FINANCE_MATRIX_CPP

#include "Matrix.h"

// Default constructor
template <typename T>
Matrix<T>::Matrix() {}

// Constructor with get_rows/get_cols specification and default values
template <typename T>
Matrix<T>::Matrix(const int& rows, const int& cols, const T& val) {
    for (int i = 0; i < rows; i++) {
        std::vector<T> col_vec (cols, val);
        mat.push_back(col_vec);
    }
}

template <typename T>
Matrix<T>::Matrix(const unsigned &_rows, const unsigned &_cols, const T &_val)
		: rows(_rows), cols(_cols) {
	
	mat.resize(_rows);
	for (unsigned i = 0; i < mat.size(); ++i) {
		mat[i].resize(_cols, _val);
	}
}

// copy constructor
template <typename T>
Matrix<T>::Matrix(const Matrix<T>& rhs) { copy(rhs); }

// overloaded assignment operator
template <typename T>
Matrix<T> &Matrix<T>::operator= (const Matrix<T>& rhs) {
    if (this == &rhs) return *this;

    unsigned new_rows = rhs.get_rows();
    unsigned new_cols = rhs.get_cols();

    mat.resize(new_rows);
    for (unsigned i = 0; i < mat.size(); i++) {
        mat[i].resize(new_cols);
    }

    for (unsigned i = 0; i < new_rows; i++) {
        for (unsigned j = 0; j < new_cols; j++) {
            mat[i][j] = rhs(i, j);
        }
    }

    rows = new_rows;
    cols = new_cols;

    return *this;
}

// Addition of two matrices
template <typename T>
Matrix <T> Matrix::operator+(const Matrix <T> &rhs) {
    Matrix matrix(rows, cols, 0.0);

    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            matrix(i, j) = this->mat[i][j] + rhs(i, j);
        }
    }
    return matrix;
}

// Cumulative addition of this matrix and another
template <typename T>
Matrix <T> &Matrix::operator+=(const Matrix <T> &rhs) {
    unsigned rows = rhs.get_rows();
    unsigned cols = rhs.get_cols();

    for (unsigned i = 0; i < rows; ++i) {
        for (unsigned j = 0; j < cols; ++j) {
            this->mat[i][j] += rhs(i, j);
        }
    }

    return *this;
}

// Subtraction of this matrix and another
template <typename T>
Matrix <T> Matrix::operator-(const Matrix <T> &rhs) {
    unsigned rows = rhs.get_rows();
    unsigned cols = rhs.get_cols();
    Matrix matrix(rows, cols, 0.0);

    for (unsigned i = 0; i < rows; ++i) {
        for (unsigned j = 0; j < cols; ++j) {
            matrix(i, j) = this->mat[i][j] - rhs(i, j);
        }
    }

    return *this;
}

// Cumulative subtraction of this matrix and another
template <typename T>
Matrix <T> Matrix::operator-=(const Matrix <T> &rhs) {
    unsigned rows = rhs.get_rows();
    unsigned cols = rhs.get_cols();

    for (unsigned i = 0; i < rows; ++i) {
        for (unsigned j = 0; j < cols; ++j) {
            this->mat[i][j] -= rhs(i, j);
        }
    }

    return *this;
}


template <typename T>
Matrix<T> Matrix::operator*(const Matrix<T> &rhs) {
    return Matrix();
}

/*template <typename T>
std::vector<std::vector<T>> Matrix<T>::get_mat() const {
    return std::vector<std::vector<T> >(mat);
}*/

template <typename T>
T& Matrix<T>::value(const int& row, const int& col) {
    return mat[row][col];
}

template <typename T>
Matrix<T>::~Matrix() {}

template <typename T>
unsigned Matrix<T>::get_rows() const {
    return this->rows;
}

template <typename T>
unsigned Matrix<T>::get_cols() const {
    return this->cols;
}

template <typename T>
void Matrix<T>::copy(const Matrix<T> &rhs) {
    mat = rhs.mat;
    rows = rhs.rows;
    cols = rhs.cols;
}




#endif






