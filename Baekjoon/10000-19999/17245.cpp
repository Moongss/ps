#include <iostream>

using ll = long long;

int N;
int com[1000][1000];
ll sum = 0;

int main() {

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> com[i][j];
            sum += com[i][j];
        }
    }

    int lo = -1; // WA: 모든 값이 0일때 1 출력함.
    int hi = 10000000;
    while (lo + 1 < hi) {
        ll tmp = 0;
        int mid = (lo + hi) / 2;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (com[i][j] <= mid)
                    tmp += com[i][j];
                else
                    tmp += mid;
            }
        }

        if (tmp >= (sum + 1) / 2) // WA: 1, 3 -> ans: 2, code: 1
            hi = mid;
        else
            lo = mid;
    }
    std::cout << hi << std::endl;
    return 0;
}