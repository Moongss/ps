#include <stdio.h>
#include <string.h>

int main(void)
{
	int check[26] = { 0, };
	char str[100][101];
	int num;
	int sum;
	char tmp;

	sum = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
		scanf("%s", str[i]);


	for (int i = 0; i < num; i++)
	{
		sum++;
		tmp = str[i][0];
		for (int j = 0; j < strlen(str[i]); j++)
		{
			if (check[str[i][j] - 'a'] == 0 || tmp == str[i][j])
				check[str[i][j] - 'a']++;
			else
			{
				sum--;
				break;
			}
			if (j < strlen(str[i]) - 1)
				tmp = str[i][j];
		}
		for (int j = 0; j < 26; j++)
			check[j] = 0;
	}
	
	printf("%d", sum);
}