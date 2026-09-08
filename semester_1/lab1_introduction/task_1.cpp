#include <iostream>
int main() {
	setlocale(LC_ALL, "RU");
	int n, m;
	std::cout << "Введите два натуральных числа: ";
	std::cin >> n >> m;
	std::cout << "Общие делители чисел " << n << " и " << m << " : ";
	for (int i = 1; i <= std::min(n, m); i++) {
		if (n % i == 0 && m % i == 0) {
			std::cout << i << " ";
		}
	}
	std::cout <<std:: endl;


	return 0;
}
