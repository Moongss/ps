#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char str[1000001];
	int		tmp[26] = { 0, };
	size_t	idx;
	char	res;
	int		max;

	idx = 0;
	max = 0;
	res = '?';
	
	scanf("%s", str);
	while (str[idx])
	{
		if (isupper(str[idx]))
			tmp[str[idx] - 'A']++;
		else if (islower(str[idx]))
			tmp[str[idx] - 'a']++;
		idx++;
	}

	for (int i = 0; i < 26; i++)
	{
		if (max < tmp[i])
		{
			max = tmp[i];
			res = i + 'A';
		}
		else if (max == tmp[i])
			res = '?';
	}
		
	printf("%c", res);
	return (0);
}