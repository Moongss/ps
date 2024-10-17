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

ll N;
ll ret = 0;
vector<int> v;
vector<int> vl, vr;
int pre[100001];
int main() {
    fastio;
    
    cin >> N; 
    ll sum = 0;
    bool f = true;
    for (int i = 1; i <= N; i++) {
        int x; cin >> x;
        if (x != 0) f = false;
        v.push_back(x); sum += x;
        pre[i] = pre[i - 1] + x;
    }

    if (sum % 4 != 0) {
        cout << 0 << endl; 
        return 0;
    }
    if (f) {
        cout << (N - 1) * (N - 2) * (N - 3) / 6;
        return 0;
    }

    for (int i = 1; i <= N; i++) {
        if (pre[i] == sum / 4) vl.push_back(i);
        if (pre[N] - pre[N - i] == sum / 4) vr.push_back(N - i);
    }
    sort(all(vr));

    for (int i = 2; i <= N - 2; i++) {
        if (pre[i] == pre[N] - pre[i]) {
            ll l = lower_bound(all(vl), i - 1) - vl.begin();
            if (*lower_bound(all(vl), i - 1) == i - 1) l++;
            ll r = vr.size() - (upper_bound(all(vr), i) - vr.begin());

            l = max(l, 0LL);
            r = max(r, 0LL);
            ret += l * r;
        }
    }
    cout << ret << endl;
    
    return 0;
}
