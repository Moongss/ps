#include <iostream>

int max(int a, int b) {
  return (a > b ? a : b);
}

int main(void){
    int dp[501] = {0};
    int save[501] = {0};
    int N, input;
    std::cin >> N;

    std::cin >> dp[1];
    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            std::cin >> input;
            save[j] = max(dp[j - 1] , dp[j]) + input;
        }

        for (int j = 1; j <= i; j++) 
        {
            dp[j] = save[j];
        }
    }

    int max = -1;
    for (int i : dp) {
        max = (i > max) ? i : max;
    }

    std::cout << max;
    return 0;
}