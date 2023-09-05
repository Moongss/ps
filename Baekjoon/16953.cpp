#include <iostream>
#include <queue>
#include <cmath>

#define MAX 10000000000

long A, B;
void solve()
{
    int operationCnt = 0;
    while (B > A)
    {
        if (B % 10 == 1)
            B /= 10;
        else if (B % 2 == 0)
            B /= 2;
        else
            break;

        operationCnt++;
    }

    if (B == A)
        std::cout << operationCnt + 1 << std::endl;
    else
        std::cout << -1 << std::endl;
}

int main()
{
    std::cin >> A >> B;
    solve();

    return 0;
}