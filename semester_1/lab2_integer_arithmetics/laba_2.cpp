#include <iostream>
#include <algorithm>
bool isKaprekar(long long n) {
    if (n <= 0) return false;
    long long sq = n * n;
    long long temp = n;
    long long divisor = 1;
    while (temp > 0) {
        divisor *= 10;
        temp /= 10;
    }
    long long left = sq / divisor;
    long long right = sq % divisor;
    return (left + right) == n;
}
int main() {
    std::setlocale(LC_ALL, "RU");
    long long A, B;
    std::cout << "Введите числа A и B (через пробел): ";
    if (!(std::cin >> A >> B)) {
        std::cout << "Ошибка ввода! Перезапустите программу." << std::endl;
        return 1;
    }
    long long start = std::min(A, B);
    long long end = std::max(A, B);
    std::cout << "\nЧисла Капрекара на отрезке [" << start << ", " << end << "]:\n";
    bool found = false;
    for (long long i = start; i <= end; ++i) {
        if (isKaprekar(i)) {
            std::cout << i << " ";
            found = true;
        }
    }
    if (!found) {
        std::cout << "На этом отрезке чисел Капрекара нет.";
    }
    std::cout << std::endl;
    return 0;
}
