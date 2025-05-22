#include "matrix_test.h"

START_TEST(mult_number_test_1) {
  int rows = 10, columns = 10;
  matrix_t A = {0}, check = {0};
  double num = get_random_value(MIN_VALUE, MAX_VALUE);

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &check);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = get_random_value(MIN_VALUE, MAX_VALUE);
      check.matrix[i][j] = A.matrix[i][j] * num;
    }
  }

  matrix_t result = {0};

  ck_assert_int_eq(s21_mult_number(&A, num, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_test_2) {
  int rows = -3, columns = -3;
  matrix_t A = {0}, check = {0};
  double num = get_random_value(MIN_VALUE, MAX_VALUE);

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &check);

  matrix_t result = {0};

  ck_assert_int_eq(s21_mult_number(&A, num, &result), INCORRECT_MATRIX);
}
END_TEST

START_TEST(mult_number_test_3) {
  matrix_t A = {0}, result = {0};
  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = INFINITY;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  double num = get_random_value(MIN_VALUE, MAX_VALUE);

  ck_assert_int_eq(s21_mult_number(&A, num, &result), CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

Suite *mult_number_tests() {
  Suite *s;
  s = suite_create("\033[33ms21_mult_number_tests\033[0m");

  TCase *tc_core;
  tc_core = tcase_create("mult_number_core");
  tcase_add_test(tc_core, mult_number_test_1);
  tcase_add_test(tc_core, mult_number_test_2);
  tcase_add_test(tc_core, mult_number_test_3);

  suite_add_tcase(s, tc_core);

  return s;
}
