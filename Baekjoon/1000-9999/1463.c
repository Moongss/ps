#include <stdio.h>

int main(void)
{
    int DP[1000001] = { 0, };
    int N;

    scanf("%d", &N);
    DP[1] = 0;
    DP[2] = 1;
    DP[3] = 1;
    for (int i = 4; i <= N; i++)
    {
        DP[i] = DP[i - 1] + 1;
        if (i % 2 == 0)
            DP[i] = (DP[i] <= DP[i / 2]) ? DP[i] : DP[i / 2] + 1;
        if (i % 3 == 0)
            DP[i] = (DP[i] <= DP[i / 3]) ? DP[i] : DP[i / 3] + 1;
    }
    printf("%d", DP[N]);
    return (0);
}