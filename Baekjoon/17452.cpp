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
vector<pii> dist[26][2];
int minIdx[26], maxIdx[26];


int main() {
    fastio;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        string str; cin >> str;
        for (int j = 0; j < sz(str); j++) {
            dist[str[j] - 'a'][0].push_back({j, i});
            dist[str[j] - 'a'][1].push_back({str.length() - 1 - j, i});
        }
    }

    for (int i = 0; i < 26; i++) {
        sort(all(dist[i][0]));
        sort(all(dist[i][1]));
    }

    int ret = 42424242;
    for (int i = 0; i < 26; i++) {
        if (sz(dist[i][0]) == 0 || sz(dist[i][1]) == 0) continue;

        int l = dist[i][0][0].first;
        for (int j = 0; j < sz(dist[i][1]); j++) {
            if (dist[i][0][0].second == dist[i][1][j].second) continue;
            ret = min(ret, l + dist[i][1][j].first);
        }

        int r = dist[i][1][0].first;
        for (int j = 0; j < sz(dist[i][0]); j++) {
            if (dist[i][1][0].second == dist[i][0][j].second) continue;
            ret = min(ret, r + dist[i][0][j].first);
        }
    }
    
    cout << (ret == 42424242 ? -1 : ret) << endl;
    return 0;
}