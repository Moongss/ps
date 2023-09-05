#include <iostream>

int main() {
    int dp[1001] = {0};
    int n;

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= 1000; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    
    std::cin >> n;
    std::cout << dp[n] % 10007;

    return 0;
}