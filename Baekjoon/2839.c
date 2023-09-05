#include <stdio.h>

int		main(void)
{
	int		num;
	int		tmp;
	int		result[5] = {1, 3, 0, 2, 4};

	tmp = -1;
	scanf("%d", &num);
	if (num >= 8)
	{
		tmp = result[(num - 3) % 5];
		tmp += (num - tmp * 3) / 5;
	}
	else
	{
		if (num % 3 == 0)
			tmp = num / 3;
		else if (num % 5 == 0)
			tmp = num / 5;
	}
	printf("%d\n", tmp);
	return (0);
}
