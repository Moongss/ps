#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int main() {
    fastio;
    int N; cin >> N;
    ll sum = 0;

    for (int i = 0; i < N; i++) {
        int P; cin >> P;
        sum ^= P;
    }

    cout << (sum ? "koosaga" : "cubelover") << endl;
    return 0;
}