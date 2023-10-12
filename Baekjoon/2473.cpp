#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int N;
ll tmp;
std::vector<ll> v;

int main() {
    std::cin >> N;

    ll tmp;
    for (int i = 0; i < N; i++) {
        std::cin >> tmp;
        v.push_back(tmp);
    }

    std::sort(v.begin(), v.end());
    ll min = 3e9 + 1;
    std::vector<ll> result;
    for (int i = 0; i < N; i++) {
        ll lo = (i == 0) ? 1 : 0;
        ll hi = (i == N - 1) ? N - 2 : N - 1;
        while (lo < hi) {
            ll tmp = v[i] + v[lo] + v[hi];
            if (std::abs(tmp) < std::abs(min)) {
                min = tmp;
                
                result.clear();
                result.push_back(v[i]);
                result.push_back(v[lo]);
                result.push_back(v[hi]);

            }
            if (tmp < 0)
                lo = (lo + 1 == i) ? lo + 2 : lo + 1;
            else
                hi = (hi - 1 == i) ? hi - 2 : hi - 1;
        }
    }

    std::sort(result.begin(), result.end());
    for (auto elem : result) {
        std::cout << elem << " ";
    }
    return 0;
}