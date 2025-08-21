#include <iostream>

using namespace std;

int main(void)
{
	int num;
	int temp;
	int num_arr[10001] = {0};
	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		scanf("%d", &temp);
		num_arr[temp]++;
	}

	for (int i = 1; i < 10001; i++)
	{
		while (num_arr[i])
		{
			printf("%d\n", i);
			num_arr[i]--;
		}
	}

	return 0;
}