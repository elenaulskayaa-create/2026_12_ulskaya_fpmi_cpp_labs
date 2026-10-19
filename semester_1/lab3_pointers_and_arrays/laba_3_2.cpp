#include <iostream>
#include <random>
int main() {
    setlocale(LC_ALL, "RU");
    int n;
    std::cout << "Введите размер массива: ";
    std::cin >> n;
    int* arr = new int[n];
    std::cout << "Выберите способ заполнения:\n1. Вручную\n2. Случайными числами\nВаш выбор: ";
    int choice;
    std::cin >> choice;
    if (choice == 1) {
        std::cout << "Введите элементы массива:\n";
        for (int i = 0; i < n; ++i) {
            std::cin >> arr[i];
        }
    }
    else if (choice == 2) {
        int a, b;
        std::cout << "Введите границы [a, b]: ";
        std::cin >> a >> b;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(a, b);
        for (int i = 0; i < n; ++i) {
            arr[i] = dist(gen);
        }
        std::cout << "Исходный массив: ";
        for (int i = 0; i < n; ++i) std::cout << arr[i] << " ";
        std::cout << "\n";
    }
    else {
        std::cout << "Неверный выбор.\n";
        delete[] arr;
        return 1;
    }
    int unique_count = 1; 
    for (int i = 1; i < n; ++i) {
        if (arr[i] != arr[unique_count - 1]) {
            arr[unique_count] = arr[i]; 
            unique_count++;
        }
    }
    for (int i = unique_count; i < n; ++i) {
        arr[i] = 0;
    }
    std::cout << "Результат: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    delete[] arr;
    return 0;
}