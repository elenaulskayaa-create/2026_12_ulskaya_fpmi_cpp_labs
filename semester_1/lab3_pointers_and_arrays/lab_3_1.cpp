#include <iostream>
#include <cmath>
#include <random>
#include <limits>
const int MAX_SIZE = 100;
int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    std::cout << "Введите размер векторов n (не более " << MAX_SIZE << "): ";
    std::cin >> n;

    if (n <= 0 || n > MAX_SIZE) {
        std::cout << "Некорректный размер!\n";
        return 1;
    }
    double x[MAX_SIZE];
    double y[MAX_SIZE];
    double z[MAX_SIZE];
    int choice;
    std::cout << "Выберите способ заполнения:\n1 - Вручную\n2 - Случайными числами\nВаш выбор: ";
    std::cin >> choice;
    if (choice == 1) {
        std::cout << "Введите элементы вектора x:\n";
        for (int i = 0; i < n; ++i) {
            std::cin >> x[i];
        }
        std::cout << "Введите элементы вектора y:\n";
        for (int i = 0; i < n; ++i) {
            std::cin >> y[i];
        }
    }
    else if (choice == 2) {
        double a, b;
        std::cout << "Введите границы интервала [a, b]: ";
        std::cin >> a >> b;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> dist(a, b);
        for (int i = 0; i < n; ++i) {
            x[i] = dist(gen);
            y[i] = dist(gen);
        }
        std::cout << "Массивы заполнены случайными числами.\n";
    }
    else {
        std::cout << "Неверный выбор!\n";
        return 1;
    }
    double dot_product = 0.0;
    for (int i = 0; i < n; ++i) {
        dot_product += x[i] * y[i];
    }
    if (dot_product == 0.0) {
        std::cout << "Скалярное произведение равно 0, деление невозможно!\n";
        return 1;
    }
    std::cout << "\nВектор z:\n";
    for (int i = 0; i < n; ++i) {
        z[i] = std::sqrt(x[i] * x[i] + y[i] * y[i]) / dot_product;
        std::cout << z[i] << " ";
    }
    std::cout << "\n";
    return 0;
}