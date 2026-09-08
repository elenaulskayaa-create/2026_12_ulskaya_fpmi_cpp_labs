#include <iostream>
int main() {
	setlocale(LC_ALL, "RU");
	int n;
	std::cout << "Введите количество нечетных чисел: ";
	std::cin >> n;
	int sum = n * n;
	std::cout << "Сумма первых "<< n << " нечетных чисел = "<<sum<<std::endl;


	return 0;
}
