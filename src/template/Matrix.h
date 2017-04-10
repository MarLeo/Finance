//
// Created by marti on 06/04/2017.
//

#ifndef FINANCE_MATRIX_H
#define FINANCE_MATRIX_H

#include <vector>
#include <iostream>

template <typename T> class Matrix {

    public:
        Matrix(); // default constructor
        Matrix(const int& rows, const int& cols, const T& val); // constructor specifying get_rows, columns and a default value
		Matrix(const unsigned& _rows, const unsigned& _cols, const T& _val);
		Matrix(const Matrix<T>& rhs); // Copy constructor
		virtual ~Matrix(); // Destructor
	
	
		// Operator overloading, for "standard" mathematical matrix operations
        Matrix<T>& operator = (const Matrix<T>& rhs);
	
		// Matrix mathematical operations
		Matrix<T> operator + (const Matrix<T>& rhs);
		Matrix<T>& operator += (const Matrix<T>& rhs);
		Matrix<T> operator - (const Matrix<T>& rhs);
		Matrix<T> operator -= (const Matrix<T>& rhs);
		Matrix<T> operator * (const Matrix<T>& rhs);
		Matrix<T> operator *= (const Matrix<T>& rhs);
		Matrix<T> transpose();
	
		// Matrix/scalar operations
		Matrix<T> operator + (const T& rhs);
		Matrix<T> operator - (const T& rhs);
		Matrix<T> operator * (const T& rhs);
		Matrix<T> operator / (const T& rhs);
	
		// Matrix/vector operations
		std::vector<T> operator * (const std::vector<T>& rhs);
		std::vector<T> diag_vec();
	
		// Access the individual elements
		T& operator() (const unsigned& row, const unsigned& col);
        const T& operator() (const unsigned& row, const unsigned& col) const ;
		

        // Access to matrix values directly, via get_rows and column indices
        //std::vector<std::vector<T> > get_mat() const;
        T& value(const int& row, const int& col);

        unsigned get_rows() const;
        unsigned get_cols() const;
	

    private:
        std::vector<std::vector<T> > mat;
        unsigned rows;
        unsigned cols;
        void copy(const Matrix<T>& rhs);
};

#include "Matrix.cpp"
#endif //FINANCE_MATRIX_H
