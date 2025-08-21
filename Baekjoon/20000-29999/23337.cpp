#include <iostream>

using ld = long double;

int N;

int main() {
    std::cin >> N;

    if (N == 1)
        std::cout << 0 << std::endl;
    else {
        ld result = N * 1.0f / (2 * N - 2);
        printf("%.6Lf", result);
    }
    return 0;
}