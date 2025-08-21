#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int main(void)
{
	int num;
	int temp;
	int foo;
	int max;
	int sum = 0;
	int cnt[8001] = {0};
	vector<int> vec;

	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &temp);
		sum += temp;
		cnt[temp + 4000]++;
		vec.push_back(temp);
	}

	printf("%d\n", static_cast<int>(round(1.0 * sum / num)));
	sort(vec.begin(), vec.end());
	printf("%d\n", vec[num/2]);

	temp = 0;
	for (int i = 0; i <= 8000; i++)
	{
		if (cnt[i] > temp)
			temp = cnt[i];
	}

	foo = 0;
	for (int i = 0; i <= 8000; i++)
	{
		if (cnt[i] == temp && foo < 2)
		{
			max = i - 4000;
			foo++;
		}
		if (foo >= 2)
			break ;
	}
	printf("%d\n", max);
	printf("%d\n", vec.back() - vec.front());

	return (0);
}
