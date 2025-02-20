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

vector<int> v, p;
set<string> s;
vector<string> ret;

int main() {
    
    int T; cin >> T;
    while (T--) {
        string S; cin >> S;
        int k; cin >> k;
        int N = S.length();

        // k의 시그마 합보다 크면 1, 2, 3, 4, 나머지.. 이런식으로 잘라서 출력.
        // 그게 아니라면 브루트포스?
        if (N >= k * (k + 1) / 2) {
            cout << "YES" << endl;
            for (int i = 1; i < k; i++) {
                cout << S.substr(0, i) << endl;
                S = S.substr(i);
            }
            cout << S << endl;
        } else {
            k--;
            bool f = true;
            v.clear(); v.resize(N+1, 0); 
            for (int i = 0; i < N-k; i++) v[i] = 0;
            for (int i = N-k; i < N; i++) v[i] = 1;

            do {
                p.clear();
                for (int i = 0; i <= N; i++) {
                    if (v[i]) p.push_back(i);
                }

                s.clear(); ret.clear();
                if (p[0] == 0 || p[p.size()-1] == N) continue;

                int prev = 0;
                for (int i = 0; i < p.size(); i++) {
                    string t = S.substr(prev, p[i] - prev);
                    s.insert(t); ret.push_back(t);
                    prev = p[i];
                }
                string t = S.substr(prev);
                s.insert(t); ret.push_back(t);

                if (s.size() == k + 1) {
                    cout << "YES" << endl;
                    for (auto str : ret) cout << str << endl;
                    f = false;
                    break;
                }
            } while (next_permutation(all(v)) && f);

            if (f) cout << "NO" << endl;
        }
    }
    return 0;
}