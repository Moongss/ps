#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;
    
    int N, M; cin >> N >> M;
    int sx, ex, sy, ey; cin >> sx >> sy >> ex >> ey;

    int dx = abs(sx - ex);
    int dy = abs(sy - ey);

    if ((dx % 2) ^ (dy % 2)) cout << "NO" << endl;
    else if (dx / 2 < M && dy / 2 < N) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}