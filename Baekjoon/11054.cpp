#include <iostream>

#define FORWARD 0
#define BACKWARD 1

int arr[1000];
int dp[2][1000] = {0, };

int main() {
    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        dp[FORWARD][i] = 1;
        for (int j = 0; j <= i; j++) {
            if (arr[i] > arr[j] && dp[FORWARD][i] < dp[FORWARD][j] + 1)
                dp[FORWARD][i] = dp[FORWARD][j] + 1;
        }

        dp[BACKWARD][N - 1 - i] = 1;
        for (int j = N - 1; j >= N - 1 - i ; j--) {
            if (arr[N - 1 - i] > arr[j] && dp[BACKWARD][N - 1 - i] < dp[BACKWARD][j] + 1)
                dp[BACKWARD][N - 1 - i] = dp[BACKWARD][j] + 1;
        }
    }

    // for (int i = 0; i < N; i++) {
    //     std::cout << i << " " << dp[FORWARD][i] << " " << dp[BACKWARD][i] << std::endl;
    // }

    int max = 0;
    for (int i = 0; i < N; i++) {
        int tmp = dp[FORWARD][i] + dp[BACKWARD][i] - 1;
        if (max < tmp) max = tmp;
    }

    std::cout << max << std::endl;
    return 0;
}