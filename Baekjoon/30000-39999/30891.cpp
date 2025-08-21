#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    
    int N, R;
    cin >> N >> R;

    vector<pii> v;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    pii result;
    int max = -1;
    for (int i = -100; i <= 100; i++) {
        for (int j = -100; j <= 100; j++) {
            int cnt = 0;
            for (auto &[x, y] : v) {
                int r = (x - i) * (x - i) + (y - j) * (y - j);
                if (r <= R * R) {
                    cnt++;
                }
            }

            if (max < cnt) {
                max = cnt;
                result = {i, j};
            }
        }
    }

    cout << result.first << " " << result.second << endl;
    return 0;
}