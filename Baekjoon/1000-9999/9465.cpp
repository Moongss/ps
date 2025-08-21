#include <iostream>

// 0 1 2 ...
// 0 0 s s s s s
// 0 0 s s s s s
int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int T, N, score;

    std::cin >> T;
    for (int k = 0; k < T; k++)
    {
        int arr[2][100000] = {
            0,
        };
        int dp[2][100003] = {
            0,
        };

        std::cin >> N;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < N; j++)
            {
                std::cin >> score;
                arr[i][j] = score;
            }
        }

        for (int j = 2; j < N + 2; j++)
        {
            int score;

            score = arr[0][j - 2];
            dp[0][j] = (dp[1][j - 1] > dp[1][j - 2]) ? dp[1][j - 1] + score : dp[1][j - 2] + score;
            score = arr[1][j - 2];
            dp[1][j] = (dp[0][j - 1] > dp[0][j - 2]) ? dp[0][j - 1] + score : dp[0][j - 2] + score;
        }

        if (dp[0][N + 1] > dp[1][N + 1])
            std::cout << dp[0][N + 1] << "\n";
        else
            std::cout << dp[1][N + 1] << "\n";
    }

    return 0;
}