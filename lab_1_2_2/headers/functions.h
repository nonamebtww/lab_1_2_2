#pragma once

// Task 1
double* f1_create_array(size_t size);

double f1_find_min(double* arr, size_t size);

double f1_multiplication(double* arr, size_t size);

void f1_reverse_print(double* arr, size_t size);

// Task 2
double** f2_create_array(size_t rows, size_t cols);

// returns column index or -1 if not found
int f2_has_column_with_equal_positive_negative(double** arr, size_t rows, size_t cols);

// Task 3
void f3_merge_sort(double* arr, size_t size);