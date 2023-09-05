#include <iostream>
#include <string>

std::string dp[101][101];

// ÆÄ½ºÄ® »ï°¢Çü ÀÌ¿ë?
//       1C0 1C1
//     2C0 2C1 2C2
//   3C0 3C1 3C2 3C3
// 4C0 4C1 4C2 4C3 4C4

std::string sum(std::string a, std::string b) {
    int carry;
    int tmp;
    std::string result = "";

    int remainALength = a.length() - 1;
    int remainBLength = b.length() - 1;
    
    // std::cout << "a : " << a << std::endl;
    // std::cout << "b : " << b << std::endl;

    carry = 0;
    while (remainALength >= 0 || remainBLength >= 0) {
        if (remainALength >= 0 && remainBLength >= 0) {
            tmp = a[remainALength] - '0' + b[remainBLength] - '0' + carry;
            remainALength--;
            remainBLength--;
        }
        else if (remainALength >= 0) {
            tmp = a[remainALength] - '0' + carry;
            remainALength--;
        }
        else if (remainBLength >= 0) {
            tmp = b[remainBLength] - '0' + carry;
            remainBLength--;
        }
        carry = tmp / 10;
        result = std::to_string(tmp % 10) + result;
    }
    if (carry > 0)
        result = std::to_string(carry) + result;
    return result;
}

int main() {
    

    dp[1][0] = "1";
    dp[1][1] = "1";

    int N, M;
    std::cin >> N >> M;
    for (int i = 2; i <= N; i++) {
        dp[i][0] = "1";
        for (int j = 1; j <= i - 1; j++) {
            // dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            dp[i][j] = sum(dp[i - 1][j], dp[i - 1][j - 1]);
        }
        dp[i][i] = "1";
    }

    std::cout << dp[N][M] << std::endl;

    return 0;
}