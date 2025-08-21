#include <stdio.h>

void	bubble_sort(int data[])
{
	int tmp;

	for (size_t i = 0; i < 9; i++)
	{
		for (size_t j = 0; j < 8 - i; j++)
		{
			if (data[j] > data[j+1])
			{
				tmp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = tmp;
			}
		}
	}
}

int main()
{
	int data[9];
	int sum;
	int i;
	int j;

	sum = 0;
	for (i = 0; i < 9; i++)
	{
		scanf("%d", &data[i]);
		sum += data[i];
	}

	for (i = 0; i < 8; i++)
	{
		for(j = i + 1; j < 9; j++)
		{
			if (sum - (data[i] + data[j]) == 100)
			{
				data[i] = data[j] = -42;
				break ;
			}
		}
		if (data[i] == -42)
			break ;
	}

	bubble_sort(data);
	for(i = 2; i < 9; i++)
		printf("%d\n", data[i]);
	return (0);
}
