#include <iostream>
int main(){
setlocale(LC_ALL, "RU");
    int number;
    std::cout << "Введите четырехзначное число: ";
    std::cin >> number;
    if (number < 1000 || number>9999) {
        std::cout << "Ошибка: число должно быть четырехзначным " << std::endl;
        return 1;
    }
    int numeral1 = number / 1000;
    int numeral2 = (number / 100)%10;
    int numeral3 = (number / 10)%10;
    int numeral4 = number %10;
    if (numeral1 == numeral4 && numeral2 == numeral3) {
        std::cout << " является палиндромом" << std::endl;
    }
    else {
        std::cout << " не является палиндромом" << std::endl;
    }
    return 0;
}

