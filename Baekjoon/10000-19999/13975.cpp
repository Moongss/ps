#include <iostream>
#include <queue>

int T, K, disk;

int main() {
	std::cin >> T;
	for (int i = 0; i < T; i++) {
		long long result = 0;
		std::priority_queue<
			long long,
			std::vector<long long>,
			std::greater<long long>>
			pq;

		std::cin >> K;
		for (int j = 0; j < K; j++) {
			std::cin >> disk;
			pq.push(disk);
			// pq.push(-disk); //underflow?
		}

		for (int j = 0; j < K - 1; j++) {
			long long elem1 = pq.top();
			pq.pop();
			long long elem2 = pq.top();
			pq.pop();

			result += (elem1 + elem2);
			pq.push(elem1 + elem2);
		}
		std::cout << result << std::endl;
	}

	return 0;
}