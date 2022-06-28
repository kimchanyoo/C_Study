#include <iostream>

int main() {
	int i, sum = 0;
	for (i = 0; i < 10; i++) {
		std::cout << i << std::endl;
		sum += i;
	}
	std::cout << "총 합은 " << sum << "입니다." << std::endl;
	return 0;
}