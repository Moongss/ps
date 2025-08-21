#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

constexpr int SZ = 1 << 17;
ll T[SZ << 1];

void Set(int x, ll v) {
    x += SZ; T[x] = v;
    while (x /= 2) T[x] = T[x*2] + T[x*2+1];
}

ll Sum(int l, int r) {
    ll res = 0;
    for (l+=SZ, r+=SZ; l<=r; l/=2, r/=2) {
        if (l % 2 == 1) res += T[l++];
        if (r % 2 == 0) res += T[r--];
    }
    return res;
}

int N, S;
vector<int> v;
vector<int> c;
int main() {
    fastio;
    
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        v.push_back(tmp);
        c.push_back(tmp);
    }
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());

    ll result = 0;
    ll curSum = 0;

    int idx;
    for (int i = 0; i < N; i++) {
        if (i < S) {
            idx = lower_bound(c.begin(), c.end(), v[i]) - c.begin();
            curSum += Sum(0, idx - 1);
            Set(idx, T[idx + SZ] + 1);
        } else {
            // sum -= cnt to (idx, N]
            idx = lower_bound(c.begin(), c.end(), v[i - S]) - c.begin();
            curSum -= Sum(idx + 1, N);
            Set(idx, T[idx + SZ] - 1);

            // sum += cnt to [0, idx)
            idx = lower_bound(c.begin(), c.end(), v[i]) - c.begin();
            curSum += Sum(0, idx - 1);
            Set(idx, T[idx + SZ] + 1);
        }
        result = max(result, curSum);
    }
    cout << result << endl;
    return 0;
}