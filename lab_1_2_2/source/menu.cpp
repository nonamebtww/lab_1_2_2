#include <iostream>
#include <format>
#include <conio.h>
#include <iomanip>

#include "functions.h"

using namespace std;

// Helpers
void print_array(double* arr, size_t size) {
    cout << "[ ";

    for (size_t i = 0; i < size; ++i) {
        cout << fixed << setprecision(4) << arr[i];
        if (i + 1 < size) cout << ", ";
    }

    cout << " ]" << endl;
}

void print_matrix(double** arr, size_t rows, size_t cols) {
    for (size_t i = 0; i < cols; ++i) {
        cout << "  Столбец " << i << ": [ ";

        for (size_t j = 0; j < rows; ++j) {
            cout << fixed << setprecision(4) << arr[i][j];
            if (j + 1 < rows) cout << ", ";
        }

        cout << " ]" << endl;
    }
}

void free_matrix(double** arr, size_t cols) {
    for (size_t i = 0; i < cols; ++i) {
        delete[] arr[i];
    }

    delete[] arr;
}

// Tasks
int menu_f1() {
    size_t size;
    cout << "Введите размер массива: ";
    cin >> size;

    double* arr = f1_create_array(size);

    if (arr == nullptr) {
        cout << "Ошибка: не удалось создать массив (некорректный размер)" << endl;
        return -1;
    }

    int action;

    do {
        cout << "Сгенерированный массив:";
        print_array(arr, size);

        cout << endl
            << "--- Операции над массивом ---" << endl
            << "1. Найти минимальный элемент" << endl
            << "2. Произведение ненулевых элементов" << endl
            << "3. Вывести в обратном порядке (без нулевых)" << endl
            << "4. Показать массив" << endl
            << "0. Назад" << endl
            << "Выберите действие: ";

        cin >> action;

        system("cls");

        switch (action) {
            case 1: {
                double min_val = f1_find_min(arr, size);
                cout << format("Минимальный элемент массива: {:.4f}", min_val) << endl;
                break;
            }
            case 2: {
                double product = f1_multiplication(arr, size);
                cout << format("Произведение ненулевых элементов: {:.4f}", product) << endl;
                break;
            }
            case 3:
                f1_reverse_print(arr, size);
                break;
            case 4:
                cout << "Текущий массив:" << endl;
                print_array(arr, size);
                break;
            default:
                cout << "Выбран неизвестный номер действия" << endl;
                break;
        }
    } while (action != 0);

    delete[] arr;
    return 0;
}

int menu_f2() {
    size_t rows, cols;
    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> cols;

    double** arr = f2_create_array(rows, cols);

    if (arr == nullptr) {
        cout << "Ошибка: не удалось создать матрицу (некорректные размеры)" << endl;
        return -1;
    }

    cout << "Сгенерированная матрица:" << endl;
    print_matrix(arr, rows, cols);

    int result = f2_has_column_with_equal_positive_negative(arr, rows, cols);

    cout << endl
        << format("Столбец с равным количеством положительных и отрицательных элементов: {} ({})", result >= 0 ? "Найден" : "Не найден", result)
        << endl;

    free_matrix(arr, cols);
    return 0;
}

int menu_f3() {
    size_t size;
    cout << "Введите размер массива: ";
    cin >> size;

    double* arr = f1_create_array(size);
    if (arr == nullptr) {
        cout << "Ошибка: не удалось создать массив (некорректный размер)" << endl;
        return -1;
    }

    cout << "Исходный массив:" << endl;
    print_array(arr, size);

    f3_merge_sort(arr, size);

    cout << "Отсортированный массив (сортировка слиянием):" << endl;
    print_array(arr, size);

    delete[] arr;
    return 0;
}

// Main menu
int menu_start() {
    int action;
    int result;

    do {
        action = 0;
        result = 0;

        cout <<
            "Лабораторная работа 2" << endl <<
            "Выполнили: Горяйнов Павел Андреевич и Рыжков Сергей Максимович" << endl <<
            "Группа: бИЦ-252" << endl <<
            "Вариант: 4" << endl << endl <<

            "1. Одномерный массив (создание, минимум, произведение, обратный вывод)" << endl <<
            "2. Двумерный массив (поиск столбца с равным кол-вом +/-)" << endl <<
            "3. Сортировка слиянием (Merge Sort)" << endl <<
            "0. Выход" << endl <<
            "Выберите действие: ";

        cin >> action;

		system("cls");

        switch (action) {
            case 0:
                break;
            case 1:
                result = menu_f1();
                break;
            case 2:
                result = menu_f2();
                break;
            case 3:
                result = menu_f3();
                break;
            default:
                cout << "Выбран неизвестный номер действия" << endl;
                break;
        }

        if (result < 0) {
            cout << "Произошла ошибка при выполнении действия" << endl;
        }

        if (action == 0) {
            cout << "Выход из программы..." << endl;
            break;
        }

        printf("\nНажмите любую клавишу для продолжения\n");
        (void)_getch();

        system("cls");
    } while (true);

    return 0;
}