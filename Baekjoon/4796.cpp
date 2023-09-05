#include <iostream>

int main() {
	int P, L, V;
	int cnt = 1;
	while (true) {
		std::cin >> L >> P >> V;
		if (P == L && L == V && P == 0)
			break;
		else
			std::cout << "Case " << cnt << ": "
					  << (V / P) * L + std::min(V % P, L) << std::endl;
		cnt++;
	}
	return 0;
}