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

int tmp[1 << 21];
set<string> s;

void insert(int cur, int node) {
    if (!tmp[node]) {
        tmp[node] = cur;
        return;
    }
    else {
        if (tmp[node] < cur) {
            insert(cur, node * 2 + 1);
        } else {
            insert(cur, node * 2);
        }
    }
}

int main() {
    fastio;
    
    int N, K; cin >> N >> K;
    for (int i = 0; i < N; i++) {
        memset(tmp, 0, sizeof(tmp));
        
        for (int j = 1; j <= K; j++) {
            int x; cin >> x; 
            insert(x, 1);
        }

        string ret = "";
        for (int j = 1; j <= (1 << K); j++) {
            if (tmp[j]) ret += to_string(j);
        }
        s.insert(ret);
    }
    cout << s.size() << endl;
    return 0;
}