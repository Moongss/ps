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
    
    int N; cin >> N;
    string s1, s2; cin >> s1 >> s2;
    
    int T; cin >> T;
    priority_queue<pair<string, int>> pq;
    while (T--) {
        int a, b; cin >> a >> b;
        swap(s1[a], s2[b]);

        if (s1 == s2) {
            pq.push({s1, 0});
            pq.push({s1, 0});
        } else {
            pq.push({s1, 1});
            pq.push({s2, 2});
        }

        cout << pq.top().y << endl;
        if (pq.top().y == 1) {s1 = pq.top().x; pq.pop(); s2 = pq.top().x;}
        else {s2 = pq.top().x; pq.pop(); s1 = pq.top().x;}
    }
    return 0;
}