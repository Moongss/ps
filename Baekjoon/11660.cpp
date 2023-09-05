#include <iostream>
#include <string>

int dp[1026][1026] = {0, };
int map[1026][1026] = {0, };

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M;
    std::cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            std::cin >> map[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + map[i][j];
        }
    }

    int x1, y1, x2, y2;
    for (int i = 0; i < M; i++) {
        std::cin >> x1 >> y1 >> x2 >> y2;
        int sum = 0;

        std::cout << dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1] << "\n";
    }
    return 0;
}