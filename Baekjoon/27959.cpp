#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    fastio;
    int N, M; cin >> N >> M;
    cout << (N * 100 >= M ? "Yes" : "No") << endl;
    return 0;
}