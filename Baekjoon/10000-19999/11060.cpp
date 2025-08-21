#include <iostream>

int N;
int A[1001];
int dp[1001];

int main() {
    std::cin >> N;
    for (int i = 1; i <= N; i++) {
        std::cin >> A[i];
        dp[i] = 4242;
    }

    dp[1] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= A[i]; j++) {
            dp[i + j] = std::min(dp[i] + 1, dp[i + j]);
        }
    }

    if (dp[N] > 1000)
        std::cout << -1 << std::endl;
    else
        std::cout << dp[N] << std::endl;
    return 0;
}