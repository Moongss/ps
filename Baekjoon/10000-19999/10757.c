#include <stdio.h>
#include <string.h>

int main(void)
{
	char	num1[100001];
	char	num2[100001];
	char	result[100002];
	int		carry = 0;
	int		tmp;
	int		num;

	scanf("%s %s", num1, num2);
	if (strlen(num1) > strlen(num2))
	{
		tmp = strlen(num1) - strlen(num2);
		memmove(num2 + (tmp),  num2, strlen(num2));
		memset(num2, '0', tmp);
	}
	else
	{
		tmp = strlen(num2) - strlen(num1);
		memmove(num1 + (tmp),  num1, strlen(num1));
		memset(num1, '0', tmp);
	}

	for (int i = strlen(num1) - 1; i >= 0; i--)
	{
		num = (num1[i] - '0') + (num2[i] - '0') + carry;
		carry = num / 10;
		result[i + 1] = num % 10 + '0';
	}
	result[0] = carry + '0';
	printf("%s\n", result + (result[0] == '0'));
}