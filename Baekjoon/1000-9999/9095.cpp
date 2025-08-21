#include <iostream>

int main() {
    int dp[11] = {0}; // n = 1 ~ 10
    int T;
    int n;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i < 11; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    std::cin >> T;
    for (int i = 0; i < T; i++) {
        std::cin >> n;
        std::cout << dp[n] << std::endl;
    }

    return 0;
}