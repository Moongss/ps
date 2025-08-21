#include <iostream>
#include <vector>

long long N, K;
int primes[200000];

int main() {
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> primes[i];
	}
	std::cin >> K;

	long long result = 0;
	for (int i = 0; i < N; i++) {
		long long currentPrime = primes[i];
		while (true) {
			long long tmp = K;
			if (tmp / currentPrime == 0)
				break;
			// std::cout << "tmp / currentPrime : " << tmp / currentPrime
			// 		  << std::endl;
			result += tmp / currentPrime;
			currentPrime *= primes[i];
		}
	}
	std::cout << result << std::endl;
	return 0;
}