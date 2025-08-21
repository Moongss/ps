#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int N, M;
ll b[200000];
std::vector<std::pair<ll, ll> > v;

int main() {
    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        std::cin >> b[i];
    }
    for (int i = 0; i < M; i++) {
        ll a, w;
        std::cin >> a >> w;
        v.push_back(std::make_pair(a, w));
    }

    std::sort(b, b + N);
    std::sort(v.begin(), v.end());

    ll lo = 0;
    ll hi = 2e9;
    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2;

        int cnt = 0;
        for (int i = 0; i < N; i++) {
            while (std::abs(b[i] - v[cnt].first) * v[cnt].second <= mid && cnt < M)
                cnt++;
            if (cnt == M)
                break;
        }

        if (cnt == M)
            hi = mid;
        else
            lo = mid;
    }
    std::cout << hi << std::endl;
    return 0;
}