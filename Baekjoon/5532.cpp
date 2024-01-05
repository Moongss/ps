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
    
    int L, A, B, C, D;
    cin >> L >> A >> B >> C >> D;

    int result = 0;
    int math = (A + C - 1) / C;
    int korean = (B + D - 1) / D;

    cout << L - max(math, korean) << endl;
    return 0;
}