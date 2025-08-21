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

int main() {
    fastio;
    
    int N; cin >> N;
    vector<int> a, b;
    a.resize(N+1); b.resize(N+1);
    int sum = 0;
    for (int i =1 ;i <= N; i++) {
        int x; cin >> x; sum += x;
        a[i] = sum;
    }
    sum = 0;
    for (int i =1; i <= N; i++) {
        int x; cin >> x; sum += x;
        b[i] = sum;
    }

    int ret = 0;
    for (int i = 1; i <= N; i++) {
        if (a[i] == b[i]) ret = i;
    }
    cout << ret << endl;
    return 0;
}