#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int T, N, M;
map<int, int> m;

vector<int> v;
vector<int> w;

int main() {
    fastio;
    
    cin >> T;
    while (T--) {
        m.clear();
        v.clear();
        cin >> N;
        for (int i = 0; i < N; i++) {
            int tmp; cin >> tmp;
            m[tmp]++;
        }
        cin >> M;
        for (int i = 0; i < M; i++) {
            int tmp; cin >> tmp;
            v.push_back(tmp);
        }

        for (auto &elem : v) {
            if (m.find(elem) != m.end()) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }
    return 0;
}