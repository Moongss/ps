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

int main() {
    fastio;
    
    int K; cin >> K;
    pii v[12];

    for (int i = 0; i < 6; i++) {
        int a, b; cin >> a >> b;
        v[i] = v[i + 6] = {a, b};
    }

    for (int i = 0; i < 8; i++) {
        if (v[i].x == v[i + 2].x && v[i + 1].x == v[i + 3].x) {
            int tmp = v[i + 1].y * v[i + 2].y;
            cout << ((v[i].y + v[i + 2].y) * (v[i + 1].y + v[i + 3].y) - tmp) * K << endl;
            break;
        }
    }
    return 0;
}