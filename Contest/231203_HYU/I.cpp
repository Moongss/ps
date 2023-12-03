#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    fastio;
    int N; cin >> N;
    pair<int, int> p;

    p = {1001, 1001};
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        if (p.second > y) {
            p = {x, y};
        }
    }
    cout << p.first << " " << p.second << endl;
    return 0;
}