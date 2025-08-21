#include <iostream>
#include <cstdio>

int dp[1002][1002];
int arr[1002][1002];

int main() {
    int N, M;

    std::cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%1d", &dp[i][j]);
        }
    }

    int max = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (dp[i][j]) {
                dp[i][j] = std::min(dp[i - 1][j], std::min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
                max = std::max(max, dp[i][j]);
            }
        }
    }

    std::cout << max * max << std::endl;
    return 0;
}