#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using ll = long long;
using ld = long double;

struct cmp {
    bool operator()(ld &a, ld &b) {
        return a < b;
    }
};

std::priority_queue<ld, std::vector<ld>, cmp> pq;

int N, K;
ll A[1000];
ll B[1000];

int main() {
    while (true) {
        std::cin >> N >> K;
        if (N == 0 && K == 0)
            break;

        for (int i = 0; i < N; i++) {
            std::cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            std::cin >> B[i];
        }

        ld lo = 0;
        ld hi = 1 + 1e-4;
        while (lo + 1e-9 < hi) {
            ld mid = (lo + hi) / 2;
            for (int i = 0; i < N; i++) {
                pq.push(B[i] * mid - A[i]);
            }

            ld sum = 0;
            for (int i = 0; i < N; i++) {
                if (i < K) {
                    pq.pop();
                    continue;
                }
                sum += pq.top();
                pq.pop();
            }

            if (sum <= 0) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        std::cout << (int)(lo * 100) << std::endl;
    }
    return 0;
}