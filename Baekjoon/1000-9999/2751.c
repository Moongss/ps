#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}
int main(void)
{
	int num;
	int* result;

	scanf("%d", &num);
	result = malloc(num * sizeof(int));
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &result[i]);
	}
	qsort(result, num, sizeof(int), cmp);
	for (int i = 0; i < num; i++)
		printf("%d\n", result[i]);
	return (0);
}

