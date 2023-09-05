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

        //RESULT = dp[i - 1]�ε�, dp[i - 1]�� ū��츦 dp[i - 1]�� �������� ����.
        //�ƴϸ� max�� result�� �־������� �ư���..
        result = max(result, dp[i]); 

        //�̰� �ٿ��� result ��� dp[i - 1]�� ���Ű�..
    }

    std::cout << result;
    return 0;
}