#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

bool map[27][27] = {
    // zeroPadding
    0,
};

int N;
int rowUpdate[4] = {1, 0, -1, 0}; // U R D L
int colUpdate[4] = {0, 1, 0, -1};

#define HOME 1
#define EMPTY 0

std::vector<int> homeStreakList;

void initPage()
{
    std::cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf("%1d", &map[i][j]); // string memory ?
        }
    }
}

std::queue<std::pair<int, int>> potentialCoords;
void BFS()
{
    int homeStreak = 1;

    while (!potentialCoords.empty())
    {
        int row = potentialCoords.front().first;
        int col = potentialCoords.front().second;

        potentialCoords.pop();
        for (int i = 0; i < 4; i++)
        {
            int newRow = row + rowUpdate[i];
            int newCol = col + colUpdate[i];

            if (map[newRow][newCol] == HOME)
            { // memory over {
                homeStreak++;
                map[newRow][newCol] = EMPTY;
                potentialCoords.push(std::pair<int, int>(newRow, newCol));
            }
        }
    }
    homeStreakList.push_back(homeStreak);
}

void solve()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (map[i][j] == HOME)
            {
                map[i][j] = EMPTY;
                potentialCoords.push(std::pair<int, int>(i, j));
                BFS();
            }
        }
    }

    std::sort(homeStreakList.begin(), homeStreakList.end());
    std::cout << homeStreakList.size() << std::endl;
    for (std::vector<int>::iterator it = homeStreakList.begin(); it != homeStreakList.end(); it++)
    {
        std::cout << *it << std::endl;
    }
}

int main()
{
    initPage();

    solve();
    return 0;
}