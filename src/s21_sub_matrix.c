#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  code_operation_e error_code = OK;

  if (A->rows != B->rows || A->columns != B->columns) {
    error_code = CALCULATION_ERROR;
  } else if (A == NULL || B == NULL || result == NULL || A->rows < 1) {
    error_code = INCORRECT_MATRIX;
  } else if (inf_or_nan(A) == CALCULATION_ERROR ||
             inf_or_nan(B) == CALCULATION_ERROR) {
    error_code = CALCULATION_ERROR;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    result->rows = A->rows;
    result->columns = A->columns;

    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }

  return error_code;
}