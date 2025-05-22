#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  code_operation_e error_code = OK;

  if (A == NULL || result == NULL || is_incorrect_matrix(A)) {
    error_code = INCORRECT_MATRIX;
  } else {
    s21_create_matrix(A->columns, A->rows, result);

    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  }

  return error_code;
}