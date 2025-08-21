#include <stdio.h>
#include <math.h>

int main(void)
{
	int A, B, N[5], num;
	int min;

	scanf("%d %d", &A, &B);
	scanf("%d", &num);

	min = (int)fabs((double)A - B);
	for(int i = 0; i < num; i++)
	{
		scanf("%d", &N[i]);
		if (min > (int)fabs((double)B - N[i]) + 1)
			min = (int)fabs((double)B - N[i]) + 1;
	}
	printf("%d\n", min);
}