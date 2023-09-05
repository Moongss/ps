#include <stdio.h>
#include <stdlib.h>

int	solve(char* str)
{
	size_t idx;
	int		result;
	int		flag;

	result = 0;
	flag = 0;
	idx = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] == 'O')
		{
			result += flag + 1;
			flag++;
		}
		else
			flag = 0;
		idx++;
	}
	return (result);
}

int main(void)
{
	int num;
	int* result;
	char str[80];

	scanf("%d", &num);
	result = (int*)malloc(num * sizeof(int));
	for (int i = 0; i < num; i++)
	{
		scanf("%s", str);
		result[i] = solve(str);
	}
	
	for (int i = 0; i < num; i++)
		printf("%d\n", result[i]);
	return (0);
}