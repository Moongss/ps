#include <stdio.h>

int main(void)
{
	int p1, p2, N;
	long M, sum = 0;
	int K[10000], cnt = 0;
	scanf("%d %ld", &N, &M);
	for(int i = 0; i < N; i++)
		scanf("%d", &K[i]);
	for(int i = 0; i < N; i++)
	{
		p1 = i;
		p2 = i;
		sum = K[i];
		while (sum < M && p2 < N)
		{
			p2++;
			sum += K[p2];
		}
		if (sum == M)
			cnt++;
	}
	printf("%d\n", cnt);
}
