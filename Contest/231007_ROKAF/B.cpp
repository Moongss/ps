#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

ll N, M;
ll P;

ll map[500][500];

int main() {
    std::cin >> N >> M >> P;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> map[i][j];
        }
        std::sort(map[i], map[i] + M);
    }

    ll isTwice = 0;
    for (int i = 0; i < N; i++) {
        isTwice = 0;
        for (int j = 0; j < M; j++) {
            if (map[i][j] == -1) {
                isTwice++;
            } else {
                if (map[i][j] <= P)
                    P += map[i][j];
                else if (isTwice > 0 && map[i][j] <= P * 2) {
                    P *= 2;
                    P += map[i][j];
                    isTwice--;
                } else {
                    std::cout << 0 << std::endl;
                    return 0;
                }
            }
        }

        while (isTwice--) {
            P *= 2;
        }
    }
    std::cout << 1 << std::endl;
    return 0;
}