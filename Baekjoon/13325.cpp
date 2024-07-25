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

int N;
ll arr[1 << 22];

ll solve(int node) {
    if (node > (1 << (N + 1))) {
        return 0;
    }

    ll left = solve(node * 2);
    ll right = solve(node * 2 + 1);
    ll diff = abs(right - left);

    if (left > right) {
        arr[node * 2 + 1] += diff;
        return left + arr[node];
    } else {
        arr[node * 2] += diff;
        return right + arr[node];
    }
}

int main() {
    fastio;
    
    cin >> N;
    for (int i = 2; i < (1 << (N + 1)); i++) {
        cin >> arr[i];
    }

    solve(1);
    ll sum = 0;
    for (int i = 2; i < (1 << (N + 1)); i++) {
        sum += arr[i];
    }
    cout << sum << endl;
    return 0;
}