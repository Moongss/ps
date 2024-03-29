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
    
    int N, A, B; cin >> N >> A >> B;
    if (A == B) cout << "Anything" << endl;
    if (A < B) cout << "Bus" << endl;
    if (A > B) cout << "Subway" << endl;
    return 0;
}