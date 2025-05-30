#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, C;
vector<int> v;

int main() {
    fastio;

    cin >> N >> C;
    v.resize(N);
    for (int i = 0; i < N; i++) cin >> v[i];

    sort(all(v));

    for (int i = 0; i < N-1; i++) {
        for (int j = i+1; j < N; j++) {
            if (v[i] + v[j] == C || v[i] == C || v[j] == C) {
                cout << 1 << endl;
                return 0;
            }

            int lo = j+1, hi = N;
            while (lo + 1 < hi) {
                int mid = (lo + hi) / 2;
                if (v[i] + v[j] + v[mid] <= C) lo = mid;
                else hi = mid;
            }
            if (v[i] + v[j] + v[lo] == C) {
                cout << 1 << endl;
                return 0;
            }
        }
    }
    cout << 0 << endl;
    return 0;
}