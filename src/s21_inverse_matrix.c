#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (A == NULL || result == NULL || is_incorrect_matrix(A)) {
    return INCORRECT_MATRIX;
  }
  code_operation_e error_code = OK;

  double determinant = 0.0;

  s21_determinant(A, &determinant);

  if (determinant != 0) {
    matrix_t complements;
    int status = s21_calc_complements(A, &complements);
    if (status == OK) {
      matrix_t temp;
      s21_create_matrix(result->columns, result->rows, &temp);

      s21_transpose(&complements, &temp);
      s21_mult_number(&temp, (1 / determinant), result);
      s21_remove_matrix(&complements);
      s21_remove_matrix(&temp);
    } else {
      error_code = CALCULATION_ERROR;
    }
  } else {
    error_code = CALCULATION_ERROR;
  }

  return error_code;
}
