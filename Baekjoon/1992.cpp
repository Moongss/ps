#include <iostream>
#include <string>

int page[64][64] = {
    0,
};

int N;
// int rowCheck[]
// int colCheck[]

void initPage()
{
    std::string input;

    for (int i = 0; i < N; i++)
    {
        std::cin >> input;
        for (int j = 0; j < N; j++)
        {
            page[i][j] = input[j] - '0';
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
        std::cout << thisPageValue;
    else
    {
        int nextMax = max / 2;
        std::cout << "(";
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                solve(startRowIdx + i * nextMax, startColIdx + j * nextMax, nextMax);
            }
        }
        std::cout << ")";
    }
}

int main()
{
    std::cin >> N;
    initPage();

    solve(0, 0, N);
    return 0;
}