#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
	char str[251];
	int A_win = 0, B_win = 0;
	int a, b;
	int deuce;

	while (1)
	{
		scanf("%s", str);
		if (str[0] == '#')
			break;
		A_win = B_win = 0;
		a = b = 0;
		deuce = 0;
		for(int i = 0; i < strlen(str); i++)
		{
			if (str[i] == 'A')
				a++;
			else
				b++;
			if (deuce && (int)fabs((double)a - b) == 2)
			{
				if (a - b == 2)
					A_win++;
				else if (b - a == 2)
					B_win++;
				deuce = a = b = 0;
			}
			else if (a == 4 || b == 4)
			{
				if (a - b >= 2)
				{
					a = b = 0;
					A_win++;
				}
				else if (b - a >= 2)
				{
					a = b = 0;
					B_win++;
				}
				else
					deuce = 1;
			}
		}
		printf("A %d B %d\n", A_win, B_win);
	}
}