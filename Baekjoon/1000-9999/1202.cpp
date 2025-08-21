#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int N, K;
struct compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, compare> jewel;
multiset<int> bag;

int main() {
    fastio;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int M, V; cin >> M >> V;
        jewel.push({M, V});
    }
    for (int i = 0; i < K; i++) {
        int C; cin >> C;
        bag.insert(C);
    }

    ll ans = 0;
    while (!jewel.empty()) {
        auto [m, v] = jewel.top(); jewel.pop();
        auto iter = bag.lower_bound(m);

        if (iter == bag.end())
            continue;
        ans += v;
        bag.erase(iter);
        if (bag.size() == 0) 
            break;
    }
    cout << ans << endl;
    return 0;
}