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
int grundy[1001];
set<int> s;
vector<int> gv;
vector<int> sv;

int main() {
    fastio;
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string str; cin >> str;
        int cnt = 0;
        for (int j = 0; j < M; j++) {
            if (str[j] == '@') {
                if (cnt) gv.push_back(cnt);
                cnt = 0; 
            }
            else cnt++;
        }
        if (cnt) gv.push_back(cnt);
    }

    int K; cin >> K;
    for (int i = 0; i < K; i++) {
        int num; cin >> num;
        sv.push_back(num);
    }
    
    bool f[1001];
    for (int i = 1, mex = 0; i <= M; i++) {
        memset(f, false, sizeof(f));
        for (auto &stick : sv) {
            if (i < stick) break;
            
            int t = 0;
            while (t <= i - stick - t) {
                f[grundy[t] ^ grundy[i - stick - t]] = true;
                t++;
            }
        }
        while (f[mex]) mex++;
        grundy[i] = mex;
    }

    int ret = 0;
    for (auto &game : gv) {
        ret ^= grundy[game];
    }
    cout << (ret ? "nein" : "hyo123bin") << endl;
    return 0;
}