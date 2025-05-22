#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  code_operation_e error_code = OK;

  if (A == NULL || result == NULL || is_incorrect_matrix(A)) {
    error_code = INCORRECT_MATRIX;
  } else if (A->rows != A->columns || A->columns == 1 || A->rows == 1) {
    error_code = CALCULATION_ERROR;
  } else {
    s21_create_matrix(A->rows, A->columns, result);

    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        matrix_t minor;
        s21_create_minor(A, i, j, &minor);
        double det = 0;
        s21_determinant(&minor, &det);
        int sign = ((i + j) % 2 == 0) ? 1 : -1;
        result->matrix[i][j] = det * sign;
        s21_remove_matrix(&minor);
      }
    }
  }

  return error_code;
}
