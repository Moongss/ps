#include <iostream>

int max(int a, int b) {
    return (a > b ? a : b);
}

int main() {
    long dp[100001] = {0};
    int n;
    int input;

    std::cin >> n;        
    for (int i = 1; i <= n; i++) {
        std::cin >> input;
        dp[i] = max(dp[i - 1] + input, input);
    }

    int result = dp[1];
    for (int i = 1; i <= n; i++)
        result = max(result, dp[i]);
    std::cout << result;
    return 0;
}