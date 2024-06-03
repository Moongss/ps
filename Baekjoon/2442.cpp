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
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - i - 1; j++) cout << " ";
        for (int j = 0; j < i * 2 + 1; j++) cout << "*";
        cout << endl;
    }
    return 0;
}