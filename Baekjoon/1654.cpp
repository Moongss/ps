#include <iostream>

using namespace std;

int main()
{
	int lan_need, lan_have, count;
	long lans[10000], start = 1, end = -1;
	long mid;
	
	cin >> lan_have >> lan_need;
	
	for (int i = 0; i < lan_have; i++)
	{
		cin >> lans[i];
		if (end < lans[i])
			end = lans[i] + 1; //overflow
	}

	while (start + 1 < end)
	{
		mid = (end + start) / 2;
		count = 0;

		for (int i = 0; i < lan_have; i++)
		{
			count += lans[i] / mid;
		}
		
		if (count >= lan_need)
			start = mid;
		else
			end = mid;
	}

	cout << start << endl;
}