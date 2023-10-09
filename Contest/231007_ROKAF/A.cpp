#include <iostream>

using ll = long long;

int N, X;
ll sum = 0;
int main() {
    std::cin >> N >> X;
    for (int i = 0; i < N; i++) {
        int tmp;
        std::cin >> tmp;
        sum += tmp;
    }

    if (sum % X == 0)
        std::cout << 1 << std::endl;
    else
        std::cout << 0 << std::endl;
    return 0;
}