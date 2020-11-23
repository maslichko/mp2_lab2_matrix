#include <gtest.h>
#include "Matrix.h"

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> A(10));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> A(MAX_MATRIX_SIZE + 1));

}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> A(-10));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> A(10);

  ASSERT_NO_THROW(TMatrix<int> B(A));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
  TMatrix<int> A(10);
  TMatrix<int> B = A;

  EXPECT_EQ(A, B);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
  TMatrix<int> A(10);
  TMatrix<int> B = A;
  B[0][0] = 1;

  EXPECT_NE(B[0][0], A[0][0]);
}

TEST(TMatrix, can_get_size)
{
  TMatrix<int> A(10);
  EXPECT_EQ(A.GetSize(), 10);
}


TEST(TMatrix, can_set_and_get_element)
{
  TMatrix<int> A(15);
  A[0][0] = 10;

  EXPECT_EQ(A[0][0], 10);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
  TMatrix<int> A(10);
  ASSERT_ANY_THROW(A[0][-3] = 10);

}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
  TMatrix<int> A(10);
  ASSERT_ANY_THROW(A[0][11] = 5);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
  TMatrix<int> A(5);
  TMatrix<int> B(5);

  ASSERT_NO_THROW(A = B);
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
  TMatrix<int> A(5);
  TMatrix<int> B(6);

  ASSERT_NO_THROW(A = B);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
  TMatrix<int> A(10);
  TMatrix<int> B(10);

  EXPECT_EQ(A == B, true);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
  TMatrix<int> A(10);

  EXPECT_EQ(A == A, true);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
  TMatrix<int> A(5);
  TMatrix<int> B(10);

  EXPECT_EQ(A == B, false);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
  TMatrix<int> A(5);
  TMatrix<int> RES(10);
  A = 10;
  EXPECT_EQ(A, RES);

}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
  TMatrix<int> A(1);
  A[0][0] = 10;
  TMatrix<int> B(1);
  B[0][0] = 20;

  TMatrix<int> res(1);
  res[0][0] = 30;


  EXPECT_EQ(A + B, res);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
  TMatrix<int> A(5);
  TMatrix<int> B(6);

  ASSERT_ANY_THROW(A + B);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
  TMatrix<int> A(1);
  A[0][0] = 20;
  TMatrix<int> B(1);
  B[0][0] = 10;

  TMatrix<int> result(1);
  result[0][0] = 10;

  EXPECT_EQ(A - B, result);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
  TMatrix<int> A(3);
  TMatrix<int> B(2);

  ASSERT_ANY_THROW(A - B);
}

TEST(TMatrix, can_multiply_matrices_with_equal_size)
{
  TMatrix<int> A(2);
  A[0][0] = 2;
  A[0][1] = 2;
  A[1][0] = 2;
  TMatrix<int> B(2);
  B[0][0] = 5;
  B[0][1] = 5;
  B[1][0] = 5;
  TMatrix<int> res(2);
  res[0][0] = 10;
  res[0][1] = 10;
  res[1][0] = 10;
  EXPECT_EQ(A * B, res);
}

TEST(TMatrix, cant_multiply_matrixes_with_not_equal_size)
{
  TMatrix<int> A(1);
  TMatrix<int> B(2);

  ASSERT_ANY_THROW(A * B);
}