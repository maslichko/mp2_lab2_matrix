#include <gtest.h>
#include "MyVector.h"

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> T(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> T(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> T(-10));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> T(5, -5));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> T(10);

  ASSERT_NO_THROW(TVector<int> T1(T));
}

TEST(TVector, can_get_size)
{
  TVector<int> T(5, 2);

  EXPECT_EQ(5, T.GetSize());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> T(4);
  T[2] = 1;

  EXPECT_EQ(1, T[2]);
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
  TVector<int> T1(5);

  TVector<int> T2(T1);

  EXPECT_EQ(T1, T2);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
  TVector<int> T1(5);
  TVector<int> T2(T1);
  T1[0] = 10;

  EXPECT_NE(T1[0], T2[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
  TVector<int> T1(5);

  ASSERT_ANY_THROW(T1[-5]);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
  TVector<int> T1(5);

  ASSERT_ANY_THROW(T1[10]);
}

TEST(TVector, can_assign_vector_to_itself)
{
  ASSERT_NO_THROW(TVector<TVector<int> > T());
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
  TVector<int> T1(5);
  TVector<int> T2(5);

  ASSERT_NO_THROW(T2 = T1);
}

TEST(TVector, can_assign_vectors_of_different_size)
{
  TVector<int> T1(4);
  TVector<int> T2(5);

  ASSERT_NO_THROW(T2 = T1);
}

TEST(TVector, compare_equal_vectors_return_true)
{
  TVector<int> T1(2);
  T1[0] = 2;
  T1[1] = 4;
  TVector<int> T2(2);
  T2[0] = 2;
  T2[1] = 4;

  EXPECT_EQ(T1 == T2, true);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
  TVector<int> T1(10);

  EXPECT_EQ(T1 == T1, true);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
  TVector<int> T1(10);
  TVector<int> T2(11);

  EXPECT_EQ(T1 == T2, false);
}

TEST(TVector, can_add_scalar_to_vector)
{
  TVector<int> T1(2);
  T1[0] = 2;
  T1[1] = 4;
  TVector<int> res(2);
  res[0] = 4;
  res[1] = 6;

  EXPECT_EQ(T1 + 2, res);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
  TVector<int> T1(2);
  T1[0] = 4;
  T1[1] = 6;
  TVector<int> res(2);
  res[0] = 2;
  res[1] = 4;

  EXPECT_EQ(T1 - 2, res);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
  TVector<int> T1(2);
  T1[0] = 4;
  T1[1] = 6;
  TVector<int> res(2);
  res[0] = 8;
  res[1] = 12;

  EXPECT_EQ(T1 * 2, res);
}

TEST(TVector, can_divide_scalar_by_vector)
{
  TVector<int> T1(2);
  T1[0] = 4;
  T1[1] = 6;
  TVector<int> res(2);
  res[0] = 2;
  res[1] = 3;

  EXPECT_EQ(T1 / 2, res);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
  TVector<int> T1(10);
  TVector<int> T2(10);

  ASSERT_NO_THROW(T2 - T1);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
  TVector<int> T1(20, 10);
  TVector<int> T2(10, 5);

  ASSERT_ANY_THROW(T2 - T1);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
  TVector<int> T1(10);
  TVector<int> T2(10);

  ASSERT_NO_THROW(T2 * T1);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
  TVector<int> T1(20, 10);
  TVector<int> T2(10, 5);

  ASSERT_ANY_THROW(T2 * T1);
}
