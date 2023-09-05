#include <iostream>

#define MINUS_PAGE -1
#define ZERO_PAGE 0
#define PLUS_PAGE 1

int page[2187][2187] = {
    0,
};

int N;
int pageSum[3] = {0, 0, 0};
// int rowCheck[]
// int colCheck[]

void initPage()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cin >> page[i][j];
        }
    }
}

void solve(int startRowIdx, int startColIdx, int max)
{
    bool isClear = true;
    int thisPageValue = page[startRowIdx][startColIdx];

    // std::cout << "[" << startRowIdx << ", " << startColIdx << ", " << max << "]\n";
    for (int i = startRowIdx; i < startRowIdx + max; i++)
    {
        for (int j = startColIdx; j < startColIdx + max; j++)
        {
            if (thisPageValue != page[i][j])
            {
                isClear = false;
                break;
            }
        }
    }

    if (isClear)
    {
        pageSum[thisPageValue + 1]++;
    }
    else
    {
        int nextMax = max / 3;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                solve(startRowIdx + i * nextMax, startColIdx + j * nextMax, nextMax);
            }
        }
    }
}

void printResult()
{
    std::cout << pageSum[MINUS_PAGE + 1] << std::endl;
    std::cout << pageSum[ZERO_PAGE + 1] << std::endl;
    std::cout << pageSum[PLUS_PAGE + 1] << std::endl;
}

int main()
{
    std::cin >> N;
    initPage();
    solve(0, 0, N);
    printResult();
    return 0;
}