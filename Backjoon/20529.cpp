#include <iostream>
#include <string>

int T, N;
std::string MBTI[100001];

void solve() {
    int minDistance = 424242;
    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            for (int k = j + 1; k < N; k++) {
                int tmp = 0;
                for (int t = 0; t < 4; t++) {
                    if (MBTI[i][t] - MBTI[j][t] != 0) tmp++;
                    if (MBTI[i][t] - MBTI[k][t] != 0) tmp++;
                    if (MBTI[j][t] - MBTI[k][t] != 0) tmp++;
                }
                if (minDistance > tmp) minDistance = tmp;
                if (minDistance == 0) {std::cout << minDistance << std::endl; return;}
            }
        }
    }
    std::cout << minDistance << std::endl;
}

int main() {
    std::cin >> T;

    for (int i = 0; i < T; i++) {
        for (int j = 0; j < 100001; j++) {
            MBTI[j] = "";
        }

        std::cin >> N;
        for (int j = 0; j < N; j++) {
            std::cin >> MBTI[j];
        }
        solve();
    }
    return 0;
}