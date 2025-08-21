#include <iostream>

int main() {
    int X, N, a, b;

    std::cin >> X >> N;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> a >> b;
        sum += a * b;
    }

    if (sum == X)
        std::cout << "Yes\n";
    else
        std::cout << "No\n";
    return 0;
}