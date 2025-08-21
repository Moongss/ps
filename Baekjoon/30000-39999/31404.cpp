#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int H, W;
int R, C, D;

int moveCnt = 0;
int rotation = 0;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int A[66][66];
int B[66][66];
int emptyCnt = 0;
bool isDust[66][66];

void init() {
    cin >> H >> W;
    cin >> R >> C >> D;
    rotation = D;
    R++; C++;

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            scanf("%1d", &A[i][j]);
        }
    }

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            scanf("%1d", &B[i][j]);
        }
    }

    memset(isDust, true, sizeof(isDust));
}

void solve() {
    while (true) {
        if (emptyCnt > 424242) break;
        if (isDust[R][C]) {
            isDust[R][C] = false;
            emptyCnt = 0;
            rotation += A[R][C];
        }
        else {
            emptyCnt++;
            rotation += B[R][C];
        }

        rotation %= 4;
        R += dx[rotation];
        C += dy[rotation];

        moveCnt++;
        if (R < 1 || R > H || C < 1 || C > W) break;
    }
    cout << moveCnt - emptyCnt << endl;
}

int main() {
    init();
    solve();
    
    return 0;
}