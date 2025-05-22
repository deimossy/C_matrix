#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  code_operation_e error_code = OK;

  if (A->columns != B->rows) {
    error_code = CALCULATION_ERROR;
  } else if (A == NULL || B == NULL || result == NULL) {
    error_code = INCORRECT_MATRIX;
  } else if (inf_or_nan(A) == CALCULATION_ERROR ||
             inf_or_nan(B) == CALCULATION_ERROR) {
    error_code = CALCULATION_ERROR;
  } else if (is_incorrect_matrix(A) || is_incorrect_matrix(B)) {
    error_code = INCORRECT_MATRIX;
  } else {
    s21_create_matrix(A->rows, B->columns, result);

    for (int row = 0; row < A->rows; row++) {
      for (int col = 0; col < B->columns; col++) {
        for (int k = 0; k < A->columns; k++) {
          result->matrix[row][col] += A->matrix[row][k] * B->matrix[k][col];
        }
      }
    }
  }

  return error_code;
}