#include <iostream>

int main() {
	int n;
	unsigned long long cnt = 0;
	std::cin >> n;

	if (n <= 2)
		std::cout << 0 << std::endl;
	else {
		for (unsigned long long i = 1; i <= n - 2; i++) {
			cnt += i * (i + 1) / 2;
		}
		std::cout << cnt << std::endl;
	}
	std::cout << 3 << std::endl;
	return 0;
}