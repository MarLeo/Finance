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
/*template <typename T>
Matrix<T>::Matrix(const int& rows, const int& cols, const T& val) {
    for (int i = 0; i < rows; i++) {
        std::vector<T> col_vec (cols, val);
        mat.push_back(col_vec);
    }
}
*/
template <typename T>
Matrix<T>::Matrix(const unsigned &_rows, const unsigned &_cols, const T &_val)
		: rows(_rows), cols(_cols) {
	
	mat.resize(_rows);
	for (unsigned i = 0; i < mat.size(); i++) {
		mat[i].resize(_cols, _val);
	}
}

// copy constructor
template <typename T>
Matrix<T>::Matrix(const Matrix<T>& rhs) { copy(rhs); }

// overloaded assignment operator
template <typename T>
Matrix<T>& Matrix<T>::operator= (const Matrix<T>& rhs) {
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
Matrix<T> Matrix<T>::operator+(const Matrix <T> &rhs) {

    /*if ((rows != rhs.rows) or (cols != rhs.cols)) {
       throw std::range_error(" problem with columns or rows dimension ");
   }*/

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
Matrix<T>& Matrix<T>::operator+=(const Matrix <T> &rhs) {
    unsigned rows = rhs.get_rows();
    unsigned cols = rhs.get_cols();

    /*if ((rows != rhs.rows) or (cols != rhs.cols)) {
        throw std::range_error(" problem with columns or rows dimension");
    }
     */

    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            this->mat[i][j] += rhs(i, j);
        }
    }

    return *this;
}

// Subtraction of this matrix and another
template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix <T> &rhs) {
    unsigned rows = rhs.get_rows();
    unsigned cols = rhs.get_cols();

    /* if ((rows != rhs.rows) or (cols != rhs.cols)) {
        throw std::range_error(" problem with columns or rows dimension");
    }
     */
    Matrix matrix(rows, cols, 0.0);

    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            matrix(i, j) = this->mat[i][j] - rhs(i, j);
        }
    }

    return *this;
}

// Cumulative subtraction of this matrix and another
template <typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix <T> &rhs) {
    unsigned rows = rhs.get_rows();
    unsigned cols = rhs.get_cols();

    /*if ((rows != rhs.rows) or (cols != rhs.cols)) {
        throw std::range_error(" problem with columns or rows dimension");
    }
     */

    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            this->mat[i][j] -= rhs(i, j);
        }
    }

    return *this;
}


template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& rhs) {
    unsigned rows = rhs.get_rows();
    unsigned cols = rhs.get_cols();

    if (cols != rows) {
        throw std::range_error("columns and rows size must coincide");
    }


    Matrix matrix(rows, cols, 0.0);

    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols ; j++) {
            for (unsigned k = 0; k < rows; k++) {
                    matrix(i, j) += this->mat[i][k] * rhs(k, j);
            }
        }
    }

    return matrix;
}

// Cumulative left multiplication of this matrix and another
template <typename T>
Matrix<T>& Matrix<T>::operator*=(const Matrix<T> &rhs) {
    /*if (cols != rhs.rows) {
        throw std::range_error("columns size must coincide");
    }
     */
    Matrix matrix = (*this) * rhs;
    (*this) = matrix;
    return *this;
}

// Calculate a transpose of this matrix
template <typename T>
Matrix<T> Matrix<T>::transpose() {
    Matrix matrix(rows, cols, 0.0);

    for (unsigned  i = 0; i < rows; ++i) {
        for (unsigned j = 0; j < cols; ++j) {
            matrix(i, j) = this->mat[j][i];
        }
    }

    return matrix;
}


// Matrix/scalar addition
template <typename T>
Matrix<T> Matrix<T>::operator+(const T& rhs) {
    Matrix matrix(rows, cols, 0.0);

    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            matrix(i, j) = this->mat[i][j] + rhs;
        }
    }
    return matrix;
}


// Matrix/scalar subtraction
template <typename T>
Matrix<T> Matrix<T>::operator-(const T& rhs) {
    Matrix matrix(rows, cols, 0.0);

    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            matrix(i, j) = this->mat[i][j] - rhs;
        }
    }
    return matrix;
}


// Matrix/scalar multiplication
template <typename T>
Matrix<T> Matrix<T>::operator*(const T& rhs) {
    Matrix matrix(rows, cols, 0.0);

    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            matrix(i, j) = this->mat[i][j] * rhs;
        }
    }
    return matrix;
}


// Matrix/scalar division
template <typename T>
Matrix<T> Matrix<T>::operator/(const T &rhs) {
    Matrix matrix(rows, cols, 0.0);

    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            matrix(i, j) = this->mat[i][j] / rhs;
        }
    }
    return Matrix(matrix);
}

// Multiply a matrix with a vector
template <typename T>
std::vector<T> Matrix<T>::operator*(const std::vector<T>& rhs) {
    std::vector<T> result(rhs.size(), 0.0);

    /*if (cols != result.size()) {
        throw std::range_error("columns size must coincide");
    }
     */

    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            result[i] = this->mat[i][j] * rhs[j];
        }
    }

    return std::vector<T>(result);
}

// Obtain a vector of the diagonal elements
template <typename T>
std::vector<T> Matrix<T>::diag_vec() {
    std::vector<T> result(rows, 0.0);

    for (unsigned i = 0; i < rows; i++) {
        result[i] = this->mat[i][i];
    }

    return std::vector<T>(result);
}

// Access the individual elements
template <typename T>
T& Matrix<T>::operator()(const unsigned &row, const unsigned &col) {
    return this->mat[row][col];
}

// Access the individual elements (const)
template <typename T>
const T& Matrix<T>::operator()(const unsigned &row, const unsigned &col) const {
    return this->mat[row][col];
}


/*template <typename T>
std::vector<std::vector<T>> Matrix<T>::get_mat() const {
    return std::vector<std::vector<T> >(mat);
}*/

/*template <typename T>
T& Matrix<T>::value(const int& row, const int& col) {
    return mat[row][col];
}
 */

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






