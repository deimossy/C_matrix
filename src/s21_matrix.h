#ifndef S21_MATRIX_SRC_S21_MATRIX_H__
#define S21_MATRIX_SRC_S21_MATRIX_H__

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define ACCURACY 1e-7

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

typedef enum { FAILURE, SUCCESS } code_error_e;

typedef enum { OK, INCORRECT_MATRIX, CALCULATION_ERROR } code_operation_e;

void s21_remove_matrix(matrix_t *A);
int s21_create_matrix(int rows, int columns, matrix_t *result);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);
void s21_create_minor(matrix_t *src, int exclude_row, int exclude_col,
                      matrix_t *minor);
int inf_or_nan(matrix_t *A);
int is_incorrect_matrix(matrix_t *A);

#endif  // S21_MATRIX_SRC_S21_MATRIX_H__