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
    
    int N, A, B;
    A = B = 0;

    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        A += tmp;
    }
    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        B += tmp;
    }
    cout << B << " " << A << endl;
    return 0;
}