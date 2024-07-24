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
    
    int T; cin >> T;
    for (int j = 1; j <= T; j++) {
        vector<pair<double, double>> v;
        int N, K; cin >> N >> K;
        v.resize(N);
        for (auto &i: v) {
            cin >> i.first >> i.second;
        }

        sort(all(v), [&](const pair<double, double> &a, const pair<double, double> &b){
            if (a.x == b.x) return a.y > b.y;
            return a.x > b.x;
        });

        vector<bool> comb(v.size(), true);
        for (int i = 0; i < N - K; i++) {
            comb[i] = false;
        }

        double sum = -1;
        do {
            bool f = true;
            double tmp = 0;
            for (int i = 0; i < N; i++) {
                if (comb[i]) {
                    if (f) {tmp += M_PI * v[i].x * v[i].x; f = !f;}
                    tmp += M_PI * v[i].x * 2 * v[i].y;
                }
            }
            sum = max(sum, tmp);
        } while (next_permutation(all(comb)));

        cout << "Case #" << j << ": ";
        cout << fixed << setprecision(6) << sum << endl;
    }
    return 0;
}