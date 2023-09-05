#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int count(unsigned long long n)
{
	unsigned long long i;
	for (i = 0; n != 0; i++)
	{
		n &= (n - 1);
	}
	return i;
}
int main()
{
	unsigned long long num;

	scanf("%lld", &num);
	printf("%d\n", count(num - 1) % 2);
}