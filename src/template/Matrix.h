//
// Created by marti on 06/04/2017.
//

#ifndef FINANCE_MATRIX_H
#define FINANCE_MATRIX_H

#include <vector>
#include <iostream>

template <typename Type = double> class Matrix {

    public:

        Matrix(); // default constructor

        // constructor specifying row, columns and a default value
        Matrix(const int& rows, const int& cols, const Type& val);

        // Copy constructor
        Matrix(const Matrix<Type>& rhs);

        // Assignement operator overload
        Matrix<Type>& operator = (const Matrix<Type>& rhs);

        // Access to matrix values directly, via row and column indices
        std::vector<std::vector<Type> > get_mat() const;
        Type& value(const int& row, const int& col);

        unsigned row() const;
        unsigned col() const;

        // Destructor
        virtual ~Matrix();

    private:
        std::vector<std::vector<Type> > mat;
};

#include "Matrix.cpp"
#endif //FINANCE_MATRIX_H
