#include <iostream>
#include <string>

std::string dp[10001];

std::string sum(std::string a, std::string b) {
    int carry;
    int tmp;
    std::string result = "";

    int aCnt = 0;
    int bCnt = 0;
    carry = 0;
    while (aCnt < a.length() || bCnt < b.length()) {
        if (aCnt < a.length() && bCnt < b.length()) {
            tmp = a[aCnt] - '0' + b[bCnt] - '0' + carry;
            aCnt++;
            bCnt++;
        }
        else if (aCnt < a.length()) {
            tmp = a[aCnt] - '0' + carry;
            aCnt++;
        }
        else if (bCnt < b.length()) {
            tmp = b[bCnt] - '0' + carry;
            bCnt++;
        }
        carry = tmp / 10;
        result += std::to_string(tmp % 10);
    }
    if (carry > 0)
        result += std::to_string(carry);
    return result;
}

int main() {
    
    dp[0] = "0";
    dp[1] = "1";
    
    int N;
    std::cin >> N;
    for (int i = 2; i <= N; i++) {
        dp[i] = sum(dp[i - 1], dp[i - 2]);
    }

    for (int i = dp[N].length() - 1; i >= 0; i--)
        std::cout << dp[N][i];

    return 0;
}