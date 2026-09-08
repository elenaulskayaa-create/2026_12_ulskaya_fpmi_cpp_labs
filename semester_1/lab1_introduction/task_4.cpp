    std::cout << "Введите шестизначное число: ";
    std::cin >> number;
    if (number < 100000 || number > 999999) {
        std::cout << "Ошибка: число должно быть шестизначным" << std::endl;
        return 1;
    }
    int digit1 = number / 100000;
    int digit2 = (number / 10000) % 10;
    int digit3 = (number / 1000) % 10;
    int digit4 = (number / 100) % 10;
    int digit5 = (number / 10) % 10;
    int digit6 = number % 10;
    int sumFirstThree = digit1 + digit2 + digit3;
    int sumLastThree = digit4 + digit5 + digit6;
    if (sumFirstThree == sumLastThree) {
        std::cout << "Число " << number << " является счастливым" << std::endl;
        std::cout << digit1 << "+" << digit2 << "+" << digit3 << " = "
            << sumFirstThree << std::endl;
        std::cout << digit4 << "+" << digit5 << "+" << digit6 << " = "
            << sumLastThree << std::endl;
    } else {
        std::cout << "Число " << number << " не является счастливым." << std::endl;
        std::cout << "Сумма первых трёх цифр: " << sumFirstThree << std::endl;
        std::cout << "Сумма последних трёх цифр: " << sumLastThree << std::endl;
    }
    return 0;
}
