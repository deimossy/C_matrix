#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  code_operation_e error_code = OK;

  if (A == NULL || result == NULL || is_incorrect_matrix(A)) {
    error_code = INCORRECT_MATRIX;
  } else if (inf_or_nan(A) == CALCULATION_ERROR || isinf(number) ||
             isnan(number)) {
    error_code = CALCULATION_ERROR;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    result->rows = A->rows;
    result->columns = A->columns;

    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }

  return error_code;
}