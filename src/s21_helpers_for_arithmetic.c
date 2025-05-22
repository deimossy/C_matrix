#include "s21_matrix.h"

int inf_or_nan(matrix_t *A) {
  code_operation_e error_code = OK;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (isinf(A->matrix[i][j]) || isnan(A->matrix[i][j])) {
        error_code = CALCULATION_ERROR;
        break;
      }
    }
  }

  return error_code;
}

int is_incorrect_matrix(matrix_t *A) { return (A->rows < 1 || A->columns < 1); }