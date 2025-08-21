#include <iostream>

int map[500][500] = {
    0,
};

int N, M;

bool block_3x2[8][3][2] = {
    {1, 0, 1, 0, 1, 1},
    {0, 1, 0, 1, 1, 1},
    {1, 1, 1, 0, 1, 0},
    {1, 1, 0, 1, 0, 1},
    {1, 0, 1, 1, 0, 1},
    {0, 1, 1, 1, 1, 0},
    {1, 0, 1, 1, 1, 0},
    {0, 1, 1, 1, 0, 1},
};

bool block_2x3[8][2][3] = {
    {1, 1, 1, 1, 0, 0},
    {1, 1, 1, 0, 0, 1},
    {1, 0, 0, 1, 1, 1},
    {0, 0, 1, 1, 1, 1},
    {0, 1, 1, 1, 1, 0},
    {1, 1, 0, 0, 1, 1},
    {0, 1, 0, 1, 1, 1},
    {1, 1, 1, 0, 1, 0},
};

int block_3x2_x[6] = {0, 1, 0, 1, 0, 1};
int block_3x2_y[6] = {0, 0, 1, 1, 2, 2};

int block_2x3_x[6] = {0, 1, 2, 0, 1, 2};
int block_2x3_y[6] = {0, 0, 0, 1, 1, 1};

int getMaxFrom4x1Block()
{
    int max = 0;
    int tmp;
    if (N - 3 > 0)
    {
        for (int i = 0; i < N - 3; i++)
        {
            for (int j = 0; j < M; j++)
            {
                tmp = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 3][j];
                            if (tmp > max)
                max = tmp;
            }

        }
    }

    if (M - 3 > 0)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M - 3; j++)
            {
                tmp = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i][j + 3];
                if (tmp > max)
                    max = tmp;
            }
        }
    }

    return (max);
}

int getMaxFrom2x2Block()
{
    int max = 0;
    int tmp;
    if (N - 1 > 0 && M - 1 > 0)
    {
        for (int i = 0; i < N - 1; i++)
        {
            for (int j = 0; j < M - 1; j++)
            {
                tmp = map[i][j] + map[i + 1][j] + map[i][j + 1] + map[i + 1][j + 1];
                if (tmp > max)
                    max = tmp;
            }
        }
    }

    return max;
}

int getMaxFrom3x2Block()
{
    int max = 0;
    int tmp;

    if (N - 2 > 0 && M - 1 > 0)
    {
        for (int i = 0; i < N - 2; i++)
        {
            for (int j = 0; j < M - 1; j++)
            {
                for (int a = 0; a < 8; a++)
                {
                    tmp = 0;
                    for (int k = 0; k < 6; k++)
                    {
                        if (block_3x2[a][block_3x2_y[k]][block_3x2_x[k]])
                            tmp += map[i + block_3x2_y[k]][j + block_3x2_x[k]];
                    }
                    if (tmp > max)
                        max = tmp;
                }
            }
        }
    }

    if (N - 1 > 0 && M - 2 > 0)
    {
        for (int i = 0; i < N - 1; i++)
        {
            for (int j = 0; j < M - 2; j++)
            {
                for (int a = 0; a < 8; a++)
                {
                    tmp = 0;
                    for (int k = 0; k < 6; k++)
                    {
                        if (block_2x3[a][block_2x3_y[k]][block_2x3_x[k]])
                            tmp += map[i + block_2x3_y[k]][j + block_2x3_x[k]];
                    }
                    if (tmp > max)
                        max = tmp;
                }
            }
        }
    }

    return max;
}

int solve()
{
    int result = 0;
    int tmp;

    result = getMaxFrom4x1Block();
    tmp = getMaxFrom2x2Block();
    if (tmp > result)
        result = tmp;
    tmp = getMaxFrom3x2Block();
    if (tmp > result)
        result = tmp;
    return result;
}
int main()
{
    std::cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            std::cin >> map[i][j];
        }
    }
    std::cout << solve() << std::endl;
    return 0;
}