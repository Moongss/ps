#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	queue<int> q;
	int n, k;
	int temp;

	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		q.push(i);

	printf("<");
	while (true) // <1, 1> -> q.size() > 1 false.
	{
		for (int idx = 1; idx < k; idx++)
		{
			temp = q.front();
			q.pop();
			q.push(temp);
		}
		printf("%d", q.front());
		q.pop();
		if (!q.size())
			break ;
		printf(", ");
	}
	printf(">\n");
	return (0);
}