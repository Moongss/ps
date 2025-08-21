#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, M;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1 ,0, 0};

char board[10][10];
pii redBall, blueBall, hole;

int solve() {
    queue<tuple<pii, pii, int>> q;
    q.push({redBall, blueBall, 1});

    while (!q.empty()) {
        auto [red, blue, cnt] = q.front();
        q.pop();

        if (cnt > 10) break;
        for (int i = 0; i < 4; i++) {
            pii nextRed = red;
            pii nextBlue = blue;

            bool redMoved = false, redInHole = false;
            bool blueMoved = false, blueInHole = false;

            while (true) {
                int nx = nextRed.first + dx[i];
                int ny = nextRed.second + dy[i];

                if (nx >= N || nx < 0 || ny >= M || ny < 0) break;
                if (board[nx][ny] == '#') break; //anyway map is surrounded by '#'
                if (board[nx][ny] == 'O') {
                    redInHole = true;
                    break;
                }
                nextRed = {nx, ny};
            }

            while (true) {
                int nx = nextBlue.first + dx[i];
                int ny = nextBlue.second + dy[i];

                if (nx >= N || nx < 0 || ny >= M || ny < 0) break;
                if (board[nx][ny] == '#') break;
                if (board[nx][ny] == 'O') {
                    blueInHole = true;
                    break;
                }

                nextBlue = {nx, ny};
            }

            if (blueInHole) continue;
            if (redInHole) return 1;

            if (nextRed != red) redMoved = true;
            if (nextBlue != blue) blueMoved = true;

            if (nextRed == nextBlue) {
                if (i == 0) {
                    if (red.second < blue.second) nextRed.second--;
                    else nextBlue.second--;
                } 
                else if (i == 1) {
                    if (red.second < blue.second) nextBlue.second++;
                    else nextRed.second++;
                }
                else if (i == 2) {
                    if (red.first < blue.first) nextRed.first--;
                    else nextBlue.first--;
                }
                else {
                    if (red.first < blue.first) nextBlue.first++;
                    else nextRed.first++;
                }
            }

            if (!redMoved && !blueMoved) continue;
            q.push({nextRed, nextBlue, cnt + 1});
        }
    }
    return 0;
}

int main() {
    fastio;
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'R') redBall = {i, j};
            if (board[i][j] == 'B') blueBall = {i, j};
            if (board[i][j] == 'O') hole = {i, j};
        }
    }

    cout << solve() << endl;

    return 0;
}