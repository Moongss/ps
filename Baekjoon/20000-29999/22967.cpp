#include <iostream>

int N;
bool arr[302][302];

int main() {
    std::cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            arr[i][j] = false;
        }
    }

    int s, e;
    int max = N * (N - 1) / 2;
    for (int i = 0; i < N - 1; i++) {
        std::cin >> s >> e;
        arr[s][e] = arr[e][s] = true;
    }

    if (max <= 2 * (N - 1)) {
        std::cout << max - (N - 1) << std::endl;
        std::cout << 1 << std::endl;
        for (int i = 1; i <= N - 1; i++) {
            for (int j = i + 1; j <= N; j++) {
                if (!arr[i][j])
                    std::cout << i << " " << j << std::endl;
            }
        }
    } else {
        int cnt = 0;
        for (int i = 2; i <= N; i++) {
            if (!arr[1][i]) cnt++;
        }
        std::cout << cnt << std::endl; // WA: K랑 R이랑 순서 잘못 출력함..
        std::cout << 2 << std::endl;
        for (int i = 2; i <= N; i++) {
            if (!arr[1][i]) std::cout << 1 << " " << i << std::endl;
        }
    }

    return 0;
}