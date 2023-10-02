#include <iostream>
#include <algorithm>

using ll = long long;

int N, C;
ll home[200000];

int main() {
    std::cin >> N >> C;
    
    for (int i = 0; i < N; i++) {
        std::cin >> home[i];
    }
    std::sort(home, home + N);
    
    ll lo = 1;
    ll hi = 1e+9 + 1;
    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2;
        ll cnt = 0;
        ll start = home[0];
        for (int i = 1; i < N; i++) {
            if (home[i] - start >= mid) {
                cnt++;
                start = home[i];
            }
        }

        if (cnt < C - 1) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    std::cout << lo << std::endl;
    return 0;
}