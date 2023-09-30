#include <iostream>

int N, H;
int lower[500001] = {0, };
int upper[500001] = {0, };

int main() {
    std::cin >> N >> H;
    for (int i = 0; i < N / 2; i++) {
        int h1, h2;
        std::cin >> h1 >> h2;
        lower[h1]++;
        upper[h2]++;
    }

    for (int i = H - 1; i >= 1; i--) {
        lower[i] += lower[i + 1];
        upper[i] += upper[i + 1];
    }

    int min = 42424242;
    int cnt = 0;
    for (int i = 1; i <= H; i++) {
        int obstacles = lower[i] + upper[H - i + 1];
        if (obstacles < min) {
            min = obstacles;
            cnt = 1;
        } else if (obstacles == min) {
            cnt++;
        }
    }
    std::cout << min << " " << cnt << std::endl;
    return 0;
}