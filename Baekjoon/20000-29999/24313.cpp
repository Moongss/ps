#include <climits>
#include <iostream>

int main() {
	long long a1, a0, c, n0;
	std::cin >> a1 >> a0 >> c >> n0;

	long long k = c - a1;
	for (int i = n0; i <= 100; i++) {
		if (a1 * i + a0 > c * i) {
			std::cout << 0 << std::endl;
			return 0;
		}
	}
	std::cout << 1 << std::endl;
	return 0;
}
