#include <iostream>

int main() {
	int H, M;
	int C;

	std::cin >> H >> M >> C;

	int newM = (M + C) % 60;
	int newH = (H + (M + C) / 60) % 24;

	std::cout << newH << " " << newM << std::endl;
	return 0;
}