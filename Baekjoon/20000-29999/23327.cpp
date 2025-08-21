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

int N, Q;
ll arr[101010];
ll pre[101010];
ll pre2[101010];

int main() {
    fastio;
    
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    for (int i = 1; i <= N; i++) pre[i] = pre[i-1] + arr[i];
    for (int i = 1; i <= N; i++) pre2[i] = pre2[i-1] + pre[i - 1] * arr[i];

    while (Q--) {
        int l, r; cin >> l >> r;
        cout << (pre2[r] - pre2[l-1]) - (pre[r]-pre[l-1]) * pre[l-1] << endl;
    }
    return 0;
}