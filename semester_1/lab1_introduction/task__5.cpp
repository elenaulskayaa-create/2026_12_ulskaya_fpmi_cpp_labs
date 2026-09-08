#include <iostream>;

int main() {
    setlocale(LC_ALL, "RU");
    int n;
    std::cout << "Введите количество чисел Фибоначчи: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Число должно быть больше 0" << std::endl;
        return 0;
    }

    long long f0 = 0, f1 = 1;
    for (int i = 0; i < n; i++) {
        std::cout << f0 << " ";
        long long next = f0 + f1;
        f0 = f1;
        f1 = next;
    }
    std::cout << std::endl;

    return 0;
}
