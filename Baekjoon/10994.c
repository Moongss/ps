#include <stdio.h>

void	print_left_str(int iter)
{
	for(int i = 0; i < iter; i++)
	{
		printf("* ");
	}
}

void	print_right_str(int iter)
{
	for(int i = 0; i < iter; i++)
	{
		printf(" *");
	}
}

void	print_star(int iter)
{
	for(int i = 0; i < iter; i++)
	{
		printf("*");
	}
}

void	print_space(int iter)
{
	for(int i = 0; i < iter; i++)
	{
		printf(" ");
	}
}

int     main(void)
{
	int num;
	int max;
	int tmp;
    
	scanf("%d", &num);
	max = 1 + (num - 1) * 4;
	for(int i = 0; i < max; i++)
	{
		tmp = (i + 1) / 2;
		if (i > max / 2)
			tmp = max / 2 - i / 2;
		print_left_str(tmp);
		if (i % 2 == 0)
			print_star(max - tmp * 4);
		else
			print_space(max - tmp * 4);
		print_right_str(tmp);
		printf("\n");
	}
}