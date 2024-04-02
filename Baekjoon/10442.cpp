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

    int N, M;
    int cnt = 0;
    while (1) {
        cin >> N;
        ++cnt;
        if (cin.eof()) break;

        map<int, int, greater<int>> m1;
        map<int, int, greater<int>> m2;
        for (int i = 0; i < N; i++) {
            int x; cin >> x;
            m1.insert({x, i});
        }
        for (int i = 0; i < N; i++) {
            int x; cin >> x;
            m2.insert({x, i});
        }

        int order = 0;
        auto m1Elem = m1.begin();
        auto m2Elem = m2.begin();
        for (int i = 0; i < N; i++) {
            ++order;

            if (m1Elem->second != m2Elem->second) {
                cout << "Case " << cnt << ": " << order << endl;
                break;
            }

            m1Elem++;
            m2Elem++;
        }
        if (order == N)
            cout << "Case " << cnt << ": agree" << endl;

        m1.clear();
        m2.clear();
    }
    return 0;
}