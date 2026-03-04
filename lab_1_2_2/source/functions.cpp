#include <iostream>
#include <random>

#define MIN_DOUBLE -1000.0
#define MAX_DOUBLE 1000.0

using namespace std;

// Task 1
double* f1_create_array(size_t size) {
	double* arr = new double[size];

	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dist(MIN_DOUBLE, MAX_DOUBLE);

	for (size_t i = 0; i < size; ++i) {
		arr[i] = dist(gen);
	}

	return arr;
}

double f1_find_min(double* arr, size_t size) {
	double min = arr[0];

	for (size_t i = 1; i < size; ++i) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}

	return min;
}

double f1_multiplication(double* arr, size_t size) {
	double result = 1.0;

	for (size_t i = 0; i < size; ++i) {
		if (arr[i] == 0.0) {
			continue;
		}

		result *= arr[i];
	}

	return result;
}

void f1_reverse_print(double* arr, size_t size) {
	cout << "Значения массива в обратном порядке, исключая нулевые значения: ";

	for (size_t i = size; i > 0; --i) {
		if (arr[i] == 0.0) {
			continue;
		}

		cout << arr[i - 1] << " ";
	}

	cout << endl;
}

// Task 2
double** f2_create_array(size_t rows, size_t cols) {
	double** arr = new double*[cols];

	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dist(MIN_DOUBLE, MAX_DOUBLE);

	for (size_t i = 0; i < cols; ++i) {
		arr[i] = new double[rows];

		for (size_t j = 0; j < rows; ++j) {
			arr[i][j] = dist(gen);
		}
	}

	return arr;
}

int f2_has_column_with_equal_positive_negative(double** arr, size_t rows, size_t cols) {
	int count_positive = 0;
	int count_negative = 0;

	for (size_t i = 0; i < cols; ++i) {
		count_positive = 0;
		count_negative = 0;

		for (size_t j = 0; j < rows; ++j) {
			if (arr[i][j] == 0.0) {
				continue;
			}

			if (arr[i][j] > 0.0) {
				++count_positive;
			} else {
				++count_negative;
			}
		}

		if (count_positive == count_negative && count_positive > 0) {
			return i;
		}
	}

	return -1;
}

// Task 3

// O(n log n)
void f3_merge_sort(double* arr, size_t size) {
	double* temp = new double[size];

	for (size_t width = 1; width < size; width *= 2) {
		for (size_t i = 0; i < size; i += 2 * width) {
			size_t left = i;
			size_t mid = i + width;
			size_t right = i + 2 * width;

			if (mid > size)   mid = size;
			if (right > size) right = size;

			size_t l = left, r = mid, k = left;
			while (l < mid && r < right) {
				if (arr[l] <= arr[r]) {
					temp[k++] = arr[l++];
				}
				else {
					temp[k++] = arr[r++];
				}
			}

			while (l < mid)   temp[k++] = arr[l++];
			while (r < right) temp[k++] = arr[r++];

			for (size_t j = left; j < right; j++) {
				arr[j] = temp[j];
			}
		}
	}

	delete[] temp;
}