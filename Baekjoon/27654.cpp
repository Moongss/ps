#include <iostream>
#include <queue>
#include <algorithm>

using ll = long long;
using ld = long double;

int N, K;
struct cmp{
    bool operator()(std::pair<ld, int>&a, std::pair<ld, int>&b) {
        return a.first > b.first;
    }
};

std::priority_queue<std::pair<ld, int>, // (D*Qi + Pi, i)
                    std::vector<std::pair<ld, int> >,
                    cmp> pq;
int P[100000];
int Q[100000];

int main() {
    std::cin >> N >> K;

    for (int i = 0; i < N; i++) {
        std::cin >> P[i] >> Q[i];
    }

    ld lo = 0;
    ld hi = 1;
    while (lo + 1e-6 < hi) {
        ld mid = (lo + hi) / 2;
        std::cout << "mid: " << mid << std::endl;
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            pq.push(std::make_pair(mid * Q[i] - P[i], i));
            std::cout << "mid * Q[i] - P[i]: " << mid * Q[i] - P[i] << std::endl;
        }

        ld sum = 0;
        for (int i = 0; i < N; i++) {
            if (i < K) {
                sum += pq.top().first;
                pq.pop();
                continue;
            }
            pq.pop();
        }

        std::cout << "sum: " << sum << std::endl;
        if (sum <= 0 && cnt > K)
            hi = mid;
        else
            lo = mid; // WIP
    }
    printf("%.6Lf\n", lo);
    return 0;
}