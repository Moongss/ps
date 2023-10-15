#include <iostream>

int R, C, H, W;
int map[3000][3000];
int pre[3000][3000];

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
    std::cin >> R >> C >> H >> W;
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            std::cin >> map[i][j];
        }
    }

    int lo = 0;
    int hi = R * C;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;

        // std::cout << "lo: " << lo << ", hi: " << hi << ", mid: " << mid << std::endl;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (map[i][j] > mid)
                    pre[i][j] = 1;
                else if (map[i][j] == mid) // WA: 80 score?
                    pre[i][j] = 0;
                else
                    pre[i][j] = -1;
            }
        }

        for (int i = 0; i < R; i++) {
            for (int j = 1; j < C; j++) {
                pre[i][j] += pre[i][j - 1];
            }
        }

        for (int i = 1; i < R; i++) {
            for (int j = 0; j < C; j++) {
                pre[i][j] += pre[i - 1][j];
            }
        }

        bool flag = false;
        for (int i = H - 1; i < R; i++) {
            for (int j = W - 1; j < C; j++) {
                int sum = pre[i][j];
                if (i - H >= 0) sum -= pre[i - H][j];
                if (j - W >= 0) sum -= pre[i][j - W];
                if (i - H >= 0 && j - W >= 0) sum += pre[i - H][j - W];

                if (sum <= 0) {
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }

        if (flag)
            hi = mid;
        else
            lo = mid;
    }
    std::cout << hi << std::endl;
    return 0;
}