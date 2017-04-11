//
// Created by marti on 08/04/2017.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../../../src/template/Matrix.h"

TEST(Matrix_Row__Test, Positive) {
    Matrix<double> matrix(5, 5, 4.0);
    EXPECT_EQ(5, matrix.get_rows());
}

TEST(Matrix_Col__Test, Positive) {
    Matrix<double> matrix(3, 3, 6.0);
    EXPECT_EQ(3, matrix.get_cols());
}

TEST(Matrix_Value__Test, Positive) {
    Matrix<double> matrix(7, 7, 9.0);
    EXPECT_DOUBLE_EQ(9.0, matrix(1, 1));
}

TEST(Matrix_Value__Test_Positive_Sum, Sum) {
    Matrix<double > a(4, 4, 1.0);
    Matrix<double > b(4, 4, 5.0);
    Matrix<double > c = a + b;

    for (int i = 0; i < c.get_rows(); i++) {
        for (int j = 0; j < c.get_cols(); j++) {
            EXPECT_DOUBLE_EQ(6.0, c(i, j));
        }
    }
}

TEST(Matrix_Exception__Test, Exception_First_Version) {
    Matrix<double > a(4, 4, 1.0);
    Matrix<double > b(5, 5, 5.0);
    try {
        Matrix<double > c = a + b;
        FAIL() << "Expected std::range_error";
    }
    catch (std::range_error err) {
        EXPECT_EQ(err.what(), std::string(" problem with columns or rows dimension "));
    }
    catch (...) {
        FAIL() << "Expected std::std::range_error";
    }
}

TEST(Matrix_Exception__Test, Exception_Second_Version) {
    Matrix<double > a(4, 4, 1.0);
    Matrix<double > b(5, 5, 5.0);
    EXPECT_THROW({
                     try {
                         Matrix<double > c = a + b;
                     }
                     catch ( const std::range_error err) {
                         EXPECT_EQ(err.what(), std::string(" problem with columns or rows dimension "));
                         throw ;
                     }
                 }, std::range_error);
}
