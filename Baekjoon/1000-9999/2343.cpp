#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())
#define sz(v) (int)v.size()
#define NO {cout << "NO" << endl; return;}
#define YES {cout << "YES" << endl; return;}

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int N, M;
ll sum;
vector<int> v;
int main() {
    fastio;

    cin >> N >> M; v.resize(N);
    for (auto &i : v) {cin >> i; sum += i;}

    ll lo = 0, hi = sum;
    while (lo + 1 < hi) {
        ll mid = lo + hi >> 1;

        ll tmp = 0;
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (v[i] > mid) {cnt = 10101010; break;}
            if (tmp + v[i] > mid) {
                cnt++;
                tmp = 0;
            }
            tmp += v[i];
        }
        if (tmp) cnt++;

        if (cnt > M) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    cout << hi << endl;    
    return 0;
}