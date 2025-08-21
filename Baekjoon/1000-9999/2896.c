#include <stdio.h>
#include <math.h>

int main()
{
	int		num[3];
	int		div[3];
	double	min;
	size_t	idx;

	scanf("%d %d %d", &num[0], &num[1], &num[2]);
	scanf("%d %d %d", &div[0], &div[1], &div[2]);

	min = 100.0;
	for(int i = 0; i < 3; i++)
	{
		if (min > (double)num[i] / div[i])
		{
			min = (double)num[i] / div[i];
			idx = i;
		}
	}

	for(int i = 0; i < 3; i++)
	{
		if (idx != i)
			printf("%f ", (double)num[i] - min * div[i]);
		else
			printf("0 ");
	}
	return (0);
}