#include <iostream>

int N, M;
int k[101][10001] = {
	0,
};

int memory[101];
int cost[101];

int main() {
	std::cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		std::cin >> memory[i];
	}
	for (int i = 1; i <= N; i++) {
		std::cin >> cost[i];
	}

	int result = 42424242;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= 10000; j++) {
			if (j >= cost[i])
				k[i][j] = std::max(
					k[i - 1][j - cost[i]] + memory[i], k[i - 1][j]);
			else
				k[i][j] = k[i - 1][j];

			if (k[i][j] >= M)
				result = std::min(result, j);
		}
	}

	std::cout << result << std::endl;
	return 0;
}