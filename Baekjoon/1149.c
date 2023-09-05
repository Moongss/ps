#include <stdio.h>

int main(void)
{
	int dp[3] = {0,};
	int in[3];
	int save[3];
	int num;

	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d %d %d", &in[0], &in[1], &in[2]);
		save[0] = (dp[1] + in[0] > dp[2] + in[0]) ? dp[2] + in[0] : dp[1] + in[0];
		save[1] = (dp[0] + in[1] > dp[2] + in[1]) ? dp[2] + in[1] : dp[0] + in[1];
		save[2] = (dp[0] + in[2] > dp[1] + in[2]) ? dp[1] + in[2] : dp[0] + in[2];
		for(int j = 0; j < 3; j++)
			dp[j] = save[j];
	}
	int min = dp[0];
	for(int i = 1; i < 3; i++)
	{
		if (min > dp[i])
			min = dp[i];
	}
	printf("%d\n", min);
}