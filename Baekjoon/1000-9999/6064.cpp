#include <iostream>

int M, N, x, y;

int gcd(int a, int b){
    if (b != 0)
        return gcd(b, a % b);
    return a;
}

int solve() {
    int max = M * N / gcd(M, N);

    x--;
    y--;
    for (int j = 0; (x + j * M) <= max; j++) {
        int tmp = (x + j * M) % N;
        if (tmp == y) {
            return ((++x) + j * M);
        }
    }
    return (-1);
}

int main() {
    int T;

    std::cin >> T;
    for (int i = 0; i < T; i++) {
        std::cin >> M >> N >> x >> y;

        std::cout << solve() << "\n";
    }

    return 0;
}