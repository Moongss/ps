#include <stdio.h>
#include <string.h>

int main(void)
{
	int num;

	int loop;
	char str[21];
	char result[1000][161];

	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &loop);
		scanf("%s", str);
		for (int j = 0; j < strlen(str) * loop; j++)
		{
			result[i][j] = str[j / loop];
		}
	}

	for (int i = 0; i < num; i++)
		printf("%s\n", result[i]);
}