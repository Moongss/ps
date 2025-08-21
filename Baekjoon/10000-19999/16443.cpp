#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int g[101][101];

void getGrundy(int x, int y) {
    if (x == 0 || y == 0 || x == y) return;

    set<int> s;
    int tmpX = x;
    int tmpY = y;
    while (tmpX - 1 > 0) {
        if (tmpX - 1 != y) 
            s.insert(g[tmpX - 1][y]);
        tmpX--;
    }
    while (tmpY - 1 > 0) {
        if (tmpY - 1 != x)
            s.insert(g[x][tmpY - 1]);
        tmpY--;
    }

    tmpX = x;
    tmpY = y;
    while (tmpX - 1 > 0 && tmpY - 1 > 0) {
        s.insert(g[tmpX - 1][tmpY - 1]);
        tmpX--;
        tmpY--;
    }

    int mex = 0;
    for (auto e : s) {
        if (mex == e) mex++;
        else break;
    }
    g[x][y] = mex;
}

int main() {
    fastio;
    
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            getGrundy(i, j);
        }
    }

    int N; cin >> N;
    int result = 0;
    while (N--) {
        int x, y; cin >> x >> y;
        if (x == 0 || y == 0 || x == y) {
            cout << "Y" << endl;
            return 0;
        }
        else {
            result ^= g[x][y];
        }
    }
    cout << (result ? "Y" : "N") << endl;
    return 0;
}