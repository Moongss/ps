#include <stdio.h>

int	solve(char* str, char find)
{
	size_t idx;

	idx = 0;
	while (str[idx])
	{
		if (find == str[idx])
			return (idx);
		idx++;
	}
	return (-1);
}

int main(void)
{
	int num;
	char str[101];

	scanf("%s", str);
	for (char i = 'a'; i <= 'z'; i++)
		printf("%d ", solve(str, i));
	return (0);
}