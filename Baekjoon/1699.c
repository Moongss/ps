#include <stdio.h>

int main(void)
{
	int num;
	int tmp;
	int dp[100001] = { 0, };

	scanf("%d", &num);
	for (int i = 0; i <= num; i++)
	{
		dp[i] = i;
	}
	for (int i = 2; i <= num; i++)
	{
		for (int j = 2; j * j <= i; j++)
		{
			tmp = dp[i - j * j] + 1;
			dp[i] = (dp[i] > tmp) ? tmp : dp[i];
		}
	}
	printf("%d\n", dp[num]);
	return (0);
}
