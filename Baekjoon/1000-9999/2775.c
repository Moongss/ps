#include <stdio.h>

long long dp[15][15];

int main(void)
{
	long long result[100000];
	int num;
	int k, n;

	for (int i = 1; i <= 14; i++)
	{
		dp[0][i] = i;
		dp[i][1] = 1;
	}

	for (int i = 1; i <= 14; i++)
	{
		for (int j = 1; j <= 14; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}

	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d %d", &k, &n);
		result[i] = dp[k][n];
	}

	for (int i = 0; i < num; i++)
		printf("%d\n", result[i]);

	return (0);
}

