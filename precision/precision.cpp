#include <iostream>
#include <iomanip>

int main () {
	double pi = 3.14159;
	double x;
	std::cout << " Input x : ";
	std::cin >> x;
	std::cout << std::setprecision (5) << pi *x << '\n';
	std::cout << std::setprecision (9) << pi *x << '\n';
	std::cout << std::fixed ;
	std::cout << std::setprecision (5) << pi *x << '\n';
	std::cout << std::setprecision (9) << pi *x << '\n';
	return 0;
}