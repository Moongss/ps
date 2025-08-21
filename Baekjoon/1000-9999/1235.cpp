#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;
vector<string> v;

int main() {
    fastio;
    
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        string x; cin >> x;
        v.push_back(x);
    }

    int cnt = 0;
    while (true) {
        cnt++;
        map<string, int> m; m.clear();
        for (auto &x : v) {
            m[x.substr(x.size() - cnt, cnt)]++;
        }

        bool flag = true;
        for (auto &x : m) {
            if (x.second != 1) {
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << cnt << endl;
            break;
        }
    }
    return 0;
}