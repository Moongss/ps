#include <stdio.h>

int 	main(void)
{
	int num;
	int n;
	int	zero[41];
	int one[41];

	zero[0] = one[1] = 1;
	zero[1] = one[0] = 0;
	scanf("%d", &num);
	for(int i = 0; i < num; i++)
	{
		scanf("%d", &n);
		for(int j = 2; j <= n; j++)
		{
			zero[j] = zero[j-1] + zero[j-2];
			one[j] = one[j-1] + one[j-2];
		}
		printf("%d %d\n", zero[n], one[n]);
	}
	return (0);
}