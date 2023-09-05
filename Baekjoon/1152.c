#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	char str[1000001];
	size_t	idx;
	int		res;
	int		flag;

	flag = 1;
	idx = 0;
	res = 0;
	gets(str);

	while (str[idx])
	{
		if (str[idx] == ' ')
			flag = 1;
		else if (isalpha(str[idx]))
		{
			if (flag == 1)
			{
				res++;
				flag = 0;
			}
		}
		idx++;
	}

	printf("%d", res);
	return (0);
}