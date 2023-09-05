#include <stdio.h>

int main(void)
{
	int loop;
	int num;
	int sum;
	int tmp;
	double res[1001];
	double ave;
	int	grade[1001];


	scanf("%d", &loop);
	for (int i = 0; i < loop; i++)
	{
		sum = 0;
		ave = 0.0;
		tmp = 0;
		scanf("%d", &num);
		for (int j = 0; j < num; j++)
		{
			scanf("%d", &grade[j]);
			sum += grade[j];
		}
		ave = sum / (double) num;
		for (int j = 0; j < num; j++)
		{
			if (ave < grade[j])
				tmp++;
		}
		res[i] = (double)tmp / num;
	}

	for (int i = 0; i < loop; i++)
		printf("%.3f%%\n", res[i] * 100);
}