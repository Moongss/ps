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
    
    // g[0][0] = 0;
    // for (int i = 1; i <= 100; i++) {
    //     for (int j = 1; j <= 100; j++) {
    //         getGrundy(i, j);
    //         // printf("%3d", g[i][j]);
    //         // if (j % 3 == 0) printf("  ");
    //     }
    //     // if (i % 3 == 0) printf("\n");
    //     // printf("\n");
    // }

    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            getGrundy(i, j);
        }
    }

    for (int i = 0; i < 5; i++) {
        int N; cin >> N;
        vector<pii> v;
        for (int j = 0; j < N; j++) {
            int x, y; cin >> x >> y;
            v.push_back({x, y});
        }

        int result = 0;
        bool flag = false;
        for (auto e : v) {
            auto [x, y] = e;
            if (x == 0 || y == 0 || x == y) {
                flag = true;
                break;
            } else {
                result ^= g[x][y];
            }
        }

        if (!flag) {
            cout << (result ? "S" : "D") << endl;
        } else {
            cout << "S" << endl;
        }
    }
    return 0;
}