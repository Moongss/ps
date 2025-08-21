#include <iostream>

int dp[30][31] = {0, };

void init() {
    for (int i = 1; i <= 30; i++) {
        dp[i][0] = dp[i][i] = 1;
    }

    for (int i = 2; i <= 30; i++) {
        for (int j = 1; j < i; j++){ 
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
}

int main() {
    init();
    int T;
    
    std::cin >> T;
    while (T--) {
        int N, M;
        std::cin >> N >> M;
        
        if (M < N)
            std::cout << dp[N][M] << std::endl;
        else
            std::cout << dp[M][N] << std::endl;
    }
    return 0;
}