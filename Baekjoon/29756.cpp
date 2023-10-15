#include <iostream>

int N;
int K;

int s[1001];
int h[1001];
int dp[1001][101];

int main() {
    std::cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        std::cin >> s[i];
    }
    for (int i = 1; i <= N; i++) {
        std::cin >> h[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 100; j++) {
            if (j - h[i] >= 0) {
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - h[i]] + s[i]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }

        for (int j = 0; j <= 100; j++) {
            dp[i][j] = std::max(dp[i][j], dp[i][std::min(j + K, 100)]);
        }
    }

    std::cout << dp[N][100] << std::endl;
    return 0;
}