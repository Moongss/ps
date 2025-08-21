#include <stdio.h>

int     main(void)
{
    int N, M;
    int result[100001] = {0, };
    int W, V;
    int max = 0;
    
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &W, &V);
        for(int j = M - W; j >= 0; j--)
        {
            if (result[j] + V > result[W+j])
                result[W+j] = result[j]+V;
        }
    }
            for(int j = 0; j <= M; j++)
        {
            if (max < result[j])
                max = result[j];
        }
        printf("%d", max);
    return (0);
}