#include "s21_matrix.h"

void s21_create_minor(matrix_t *src, int exclude_row, int exclude_col,
                      matrix_t *minor) {
  int new_size = src->rows - 1;
  s21_create_matrix(new_size, new_size, minor);

  for (int i = 0, mi = 0; i < src->rows; i++) {
    if (i == exclude_row) continue;
    for (int j = 0, mj = 0; j < src->columns; j++) {
      if (j == exclude_col) continue;
      minor->matrix[mi][mj++] = src->matrix[i][j];
    }
    mi++;
  }
}

int s21_determinant(matrix_t *A, double *result) {
  code_operation_e error_code = OK;

  if (A->rows != A->columns) {
    error_code = CALCULATION_ERROR;
  } else if (A == NULL || result == NULL || is_incorrect_matrix(A)) {
    error_code = INCORRECT_MATRIX;
  } else {
    if (A->rows == 1) {
      *result = A->matrix[0][0];
    } else if (A->rows == 2) {
      *result =
          A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
    } else {
      double det = 0.0;
      int sign = 1;
      for (int col = 0; col < A->columns; col++) {
        matrix_t minor;
        s21_create_minor(A, 0, col, &minor);

        double minor_det;
        s21_determinant(&minor, &minor_det);
        s21_remove_matrix(&minor);

        det += sign * A->matrix[0][col] * minor_det;
        sign *= -1;
      }

      *result = det;
    }
  }

  return error_code;
}
