#include <iostream>

int N, L;
long sum[1000001] = {
	0,
};
int main() {
	std::cin >> N >> L;

	for (int i = 1; i <= N; i++) {
		std::cin >> sum[i];
		sum[i] += sum[i - 1];
	}

	int result = 0;
	for (int i = 1; i <= N; i++) {
		long alcoholLevel = (i <= L) ? sum[i] : (sum[i] - sum[i - L]);

		if (alcoholLevel >= 129 && alcoholLevel <= 138)
			result++;
	}
	std::cout << result << std::endl;
	return 0;
}