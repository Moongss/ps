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
    
    int N; cin >> N;
    while (N--) {
        double a1, p1, r1, p2;
        cin >> a1 >> p1 >> r1 >> p2;

        if (p1 * r1 * r1 * M_PI < a1 * p2) cout << "Slice of pizza" << endl;
        else cout << "Whole pizza" << endl;
    }
    return 0;
}