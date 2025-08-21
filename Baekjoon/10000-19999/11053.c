#include <stdio.h>

int 	main(void)
{
	int dp[1001] = {0,};
	int in[1001];
	int num;
	int max;

	scanf("%d", &num);
	for(int i = 1; i <= num; i++)
	{
		scanf("%d", &in[i]);
	}	

	for(int i = 1; i <= num; i++)
	{
		dp[i] = 1;
		for(int j = 1; j <= i; j++)
		{
			if (in[i] > in[j] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}
	}
	
	max = dp[1];
	for(int i = 2; i <= num; i++)
	{
		max = (max < dp[i]) ? dp[i] : max;
	}
	printf("%d\n", max);
}