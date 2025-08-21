#include <iostream>
#include <vector>
#include <queue>

std::vector<int> arr[100001];
int result[100001] = {
    0,
};

void solve(int start)
{
    int currentNode;
    std::queue<int> nodeQueue;
    nodeQueue.push(start);

    while (!nodeQueue.empty())
    {
        currentNode = nodeQueue.front();
        nodeQueue.pop();

        for (std::vector<int>::iterator iter = arr[currentNode].begin(); iter != arr[currentNode].end(); iter++)
        {
            if (result[*iter] == 0)
            {
                nodeQueue.push(*iter);
                result[*iter] = currentNode;
            }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int N;
    int a, b;
    int i;

    std::cin >> N;
    for (i = 0; i < N - 1; i++)
    {
        std::cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    solve(1);

    for (int i = 2; i <= N; i++)
        std::cout << result[i] << "\n";
    return 0;
}