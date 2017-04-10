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
    EXPECT_DOUBLE_EQ(9.0, matrix.value(1, 1));
}