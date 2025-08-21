#include <iostream>

int max(int a, int b) {
    return (a > b ? a : b);
}

int main() {
    long dp[10001] = {0};
    int input[10001] = {0};
    int result = 0;
    int n;

    std::cin >> n;        
    for (int i = 1; i <= n; i++) {
        std::cin >> input[i];
    }

    dp[1] = input[1];
    dp[2] = input[1] + input[2];
    result = max(dp[1], dp[2]);

    for (int i = 3; i <= n; i++) {

        dp[i] = max(max(result, dp[i - 2] + input[i]), dp[i - 3] + input[i - 1] + input[i]);

        //RESULT = dp[i - 1]인데, dp[i - 1]가 큰경우를 dp[i - 1]로 저장하지 않음.
        //아니면 max에 result를 넣어줬으면 됐겠지..
        result = max(result, dp[i]); 

        //이걸 줄여서 result 대신 dp[i - 1]로 쓴거고..
    }

    std::cout << result;
    return 0;
}