#include <stdio.h>

void	print_elem(int cnt, int elem, int N)
{
	if (N == 1)
		printf("<%d>\n", elem);
	else
	{
		if (cnt == 0)
			printf("<%d, ", elem);
		else if (cnt == N - 1)
			printf("%d>\n", elem);
		else
			printf("%d, ", elem);
	}
}

int main(void)
{
	int		num[5000];
	int		N, K;
	int		tmp = 1, cnt = 0, idx = 0;

	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; i++)
		num[i] = i + 1;
	while (cnt < N)
	{
		if (num[idx] != 0)
		{
			if (tmp != K)
				tmp++;
			else
			{
				print_elem(cnt, num[idx], N);
				num[idx] = 0;
				tmp = 1;
				cnt++;
			}
		}
		idx = (idx + 1) % N;
	}
}