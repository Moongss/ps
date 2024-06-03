#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int main() {
    fastio;
    int N; string str; cin >> N >> str;

    int people = 0;
    int S = 0;
    int L = 0;

    for (auto &x : str) {
        if (x == 'S') {
            S++;
        } else {
            L++;
        }
        people++;
    }

    cout << min(people, S + 1 + L / 2) << endl;
    return 0;
}