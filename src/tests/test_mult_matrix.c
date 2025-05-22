#include "matrix_test.h"

START_TEST(mult_matrix_test_1) {
  matrix_t A = {0}, B = {0}, check = {0};

  s21_create_matrix(2, 3, &A);
  A.matrix[0][0] = 3;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0.1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 5;

  s21_create_matrix(3, 2, &B);
  B.matrix[0][0] = 3;
  B.matrix[0][1] = 3;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 3;
  B.matrix[2][0] = 3.5;
  B.matrix[2][1] = 1;

  s21_create_matrix(2, 2, &check);
  check.matrix[0][0] = 21.35;
  check.matrix[0][1] = 21.1;
  check.matrix[1][0] = 26.5;
  check.matrix[1][1] = 14;

  matrix_t result = {0};

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_test_2) {
  int rows_1 = 10, columns_1 = 5;
  int rows_2 = 10, columns_2 = 5;
  matrix_t A = {0}, B = {0};

  s21_create_matrix(rows_1, columns_1, &A);
  for (int i = 0; i < rows_1; i++) {
    for (int j = 0; j < columns_1; j++) {
      A.matrix[i][j] = get_random_value(MIN_VALUE, MAX_VALUE);
    }
  }

  s21_create_matrix(rows_2, columns_2, &B);
  for (int i = 0; i < rows_2; i++) {
    for (int j = 0; j < columns_2; j++) {
      B.matrix[i][j] = get_random_value(MIN_VALUE, MAX_VALUE);
    }
  }

  matrix_t result = {0};

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_test_3) {
  int rows = -3, columns = -3;
  matrix_t A = {0}, B = {0};

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  matrix_t result = {0};

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), INCORRECT_MATRIX);
}
END_TEST

START_TEST(mult_matrix_test_4) {
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);

  A.matrix[0][0] = NAN;

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *mult_matrix_suite() {
  Suite *s;
  s = suite_create("\033[33ms21_mult_matrix_tests\033[0m");

  TCase *tc_core;
  tc_core = tcase_create("mult_matrix_core");

  tcase_add_test(tc_core, mult_matrix_test_1);
  tcase_add_test(tc_core, mult_matrix_test_2);
  tcase_add_test(tc_core, mult_matrix_test_3);
  tcase_add_test(tc_core, mult_matrix_test_4);

  suite_add_tcase(s, tc_core);

  return s;
}