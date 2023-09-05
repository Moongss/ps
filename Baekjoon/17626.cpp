#include <iostream>
#include <cmath>

int min(int &a, int &b) {
    if (a > b)
        return b;
    return a;
}

int main() {
    int N, tmp;
    int squares[50001];

    squares[1] = 1;
    std::cin >> N;
    for (int i = 2; i <= N; i++) {
        tmp = 50000;
        for (int j = 1; j * j <= i; j++) {
            tmp = min(tmp, squares[i - j * j]);
        }
        squares[i] = tmp + 1;
    }
    std::cout << squares[N] << std::endl;
    return 0;
}