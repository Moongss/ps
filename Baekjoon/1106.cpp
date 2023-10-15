#include <iostream>

int N, C;
int price[21];
int customer[21];
int dp[21][1001];

int main() {
    std::cin >> C >> N;

    for (int i = 1; i <= N; i++) {
        std::cin >> price[i] >> customer[i];
    }

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= C; j++) {
            dp[i][j] = 42424242;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= C; j++) {
            int k = 1;

            dp[i][j] = dp[i - 1][j]; //WA
            while (true) {
                if (j - customer[i] * k <= 0) {
                    dp[i][j] = std::min(dp[i][j], k * price[i]);
                    break;
                } else {
                    dp[i][j] = std::min(dp[i][j], dp[i - 1][j - customer[i] * k] + price[i] * k);
                }
                k++;
            }
        }
    }

    std::cout << dp[N][C] << std::endl;
    return 0;
}