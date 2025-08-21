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
vector<int> v;

int main() {
    fastio;
    
    cin >> N;
    v.resize(N); for (auto &i : v) cin >> i;

    int mmax = -1;
    int cnt = 1;
    int cnt2 = 1;
    for (int i = 1; i < N; i++) {
        if (v[i] >= v[i - 1]) cnt++;
        else {
            mmax = max(mmax, cnt);
            cnt = 1;
        }

        if (v[i] <= v[i - 1]) cnt2++;
        else {
            mmax = max(mmax, cnt2);
            cnt2 = 1;
        }
    }
    mmax = max(mmax, max(cnt, cnt2));
    cout << mmax << endl;
    return 0;
}