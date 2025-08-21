#include <stdio.h>
#include <string.h>

int main()
{
	char str[30];
	int	 flag;
	int  jaeum;
	int  moeum;
	int  flag2;
	int  flag3;
	while (1)
	{
		scanf("%s", str);
		if (!strcmp(str, "end")) break;
		flag = 0;
		flag2 = 0;
		flag3 = 0;
		jaeum = 0;
		moeum = 0;
		for (int i = 0; i < strlen(str); i++)
		{
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'o' || str[i] == 'i' || str[i] == 'u')
			{
				jaeum = 0;
				moeum++;
				flag = 1;
			}
			else
			{
				moeum = 0;
				jaeum++;
			}
			if (str[i] == str[i + 1] && (str[i] != 'e' && str[i] != 'o'))
				flag2 = 1;
			else if (moeum >= 3 || jaeum >= 3)
				flag3 = 1;
		}
		if (!flag || flag2 || flag3)
			printf("<%s> is not acceptable.\n", str);
		else
			printf("<%s> is acceptable.\n", str);
	}
	return (0);
}