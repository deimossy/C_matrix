#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  code_error_e code_error = FAILURE;

  if (A->rows == B->rows && A->columns == B->columns) {
    code_error = SUCCESS;

    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > ACCURACY) {
          code_error = FAILURE;
          break;
        }
      }
    }
  }

  return code_error;
}
