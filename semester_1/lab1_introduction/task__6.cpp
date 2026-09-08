#include <iostream>
int main() {
    setlocale(LC_ALL, "RU");
    int a, b, d;
    std::cout << "Введите a (первый член), b (последний член), d (разность): ";
    std::cin >> a >> b >> d;
    if (d == 0) {
        std::cout << "Разность не может быть равна 0" << std::endl;
        return 1;
    }
    int step = (d > 0) ? 1 : -1;
    int current = a;

    std::cout << "Члены прогрессии, кратные 3 и лежащие на отрезке [" << a << ", " << b << "]:" << std::endl;
    bool found = false;
    while ((step == 1 && current <= b) || (step == -1 && current >= b)) {
        if (current % 3 == 0) {
            std::cout << current << " ";
            found = true;
        }
        current += d;
    }

    if (!found) {
        std::cout << "Нет таких членов";
    }
    std::cout << std::endl;

    return 0;
}
