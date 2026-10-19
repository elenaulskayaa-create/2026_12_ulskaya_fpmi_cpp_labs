#include <iostream>
#include <cstdlib>
#include <ctime>
#include <clocale>

void inputSize(int& n, int& m) {
    std::cout << "Введите количество строк (n): ";
    std::cin >> n;
    std::cout << "Введите количество столбцов (m): ";
    std::cin >> m;
}

int** createMatrix(int n, int m) {
    int** matrix = new int* [n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[m];
    }
    return matrix;
}

void fillMatrixManual(int** matrix, int n, int m) {
    std::cout << "Введите элементы матрицы (" << n * m << " шт.):" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << "Элемент [" << i + 1 << "][" << j + 1 << "]: ";
            std::cin >> matrix[i][j];
        }
    }
}

void fillMatrixRandom(int** matrix, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrix[i][j] = std::rand() % 16 - 5;
        }
    }
    std::cout << "Матрица успешно заполнена случайными числами." << std::endl;
}

void printMatrix(int** matrix, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void findMaxPositiveSubmatrix(int** A, int n, int m) {
    int max_area = 0;
    int best_r = 0, best_q = 0;
    int best_row = 0, best_col = 0;

    for (int row1 = 0; row1 < n; ++row1) {
        for (int col1 = 0; col1 < m; ++col1) {
            for (int row2 = row1; row2 < n; ++row2) {
                for (int col2 = col1; col2 < m; ++col2) {

                    bool all_positive = true;
                    for (int i = row1; i <= row2; ++i) {
                        for (int j = col1; j <= col2; ++j) {
                            if (A[i][j] <= 0) {
                                all_positive = false;
                                break;
                            }
                        }
                        if (!all_positive) break;
                    }

                    if (all_positive) {
                        int current_r = row2 - row1 + 1;
                        int current_q = col2 - col1 + 1;
                        int current_area = current_r * current_q;

                        if (current_area > max_area) {
                            max_area = current_area;
                            best_r = current_r;
                            best_q = current_q;
                            best_row = row1;
                            best_col = col1;
                        }
                    }
                }
            }
        }
    }

    if (max_area == 0) {
        std::cout << "\n[!] Подматрица, состоящая только из положительных элементов, не найдена." << std::endl;
        std::cout << "Задача не может быть решена." << std::endl;
    }
    else {
        std::cout << "\n--- Результат ---" << std::endl;
        std::cout << "Размер максимальной подматрицы: " << best_r << " x " << best_q << " (r x q)" << std::endl;
        std::cout << "Координаты левого верхнего элемента: Строка " << best_row + 1 << ", Столбец " << best_col + 1 << std::endl;

        std::cout << "Сама подматрица P:" << std::endl;
        for (int i = best_row; i < best_row + best_r; ++i) {
            for (int j = best_col; j < best_col + best_q; ++j) {
                std::cout << A[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    }
}

void deleteMatrix(int** matrix, int n) {
    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    std::setlocale(LC_ALL, "Russian");
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    int n, m;

    inputSize(n, m);

    int** A = createMatrix(n, m);

    int choice;
    std::cout << "\nВыберите способ заполнения матрицы:" << std::endl;
    std::cout << "1. Вручную с клавиатуры" << std::endl;
    std::cout << "2. Случайными числами" << std::endl;
    std::cout << "Ваш выбор: ";
    std::cin >> choice;
    if (choice == 1) {
        fillMatrixManual(A, n, m);
    }
    else {
        fillMatrixRandom(A, n, m);
    }

    std::cout << "\nИсходная матрица A:" << std::endl;
    printMatrix(A, n, m);

    findMaxPositiveSubmatrix(A, n, m);

    deleteMatrix(A, n);

    return 0;
}