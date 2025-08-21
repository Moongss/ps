#include <stdio.h>

int main(void)
{
	int num;
	long a, b, tmp;

	a = 0;
	b = 1;
	scanf("%d", &num);
	if (num <= 1)
		printf("%d", num);
	else
	{
		for(int i = 2; i <= num; i++)
		{
			tmp = a + b;
			a = b;
			b = tmp;
		}
		printf("%ld", tmp);
	}
}