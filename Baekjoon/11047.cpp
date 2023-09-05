#include <iostream>

int main() {
    int N, K;
    int coinCnt = 0;
    int coinValue[11];
    int currentCoinIndex;

    std::cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        std::cin >> coinValue[i];
    }

    currentCoinIndex = N;
    while (K) {
        if (K / coinValue[currentCoinIndex] > 0) {
            coinCnt += K / coinValue[currentCoinIndex];
            K %= coinValue[currentCoinIndex];
        }
        currentCoinIndex--;
    }

    std::cout << coinCnt << std::endl;
}