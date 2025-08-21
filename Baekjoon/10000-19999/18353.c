#include <stdio.h>

int main(void)
{
	int N;
	int in[2000];
	int dp[2000];
	int max;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &in[i]);

	for (int i = 0; i < N; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (dp[i] < dp[j] + 1 && in[j] > in[i])
			{
				dp[i] = dp[j] + 1;
			}
		}
	}

	max = 0;
	for (int i = 0; i < N; i++)
		max = (max < dp[i]) ? dp[i] : max;
	printf("%d\n", N - max);
}
