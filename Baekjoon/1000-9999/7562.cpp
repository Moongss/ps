#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
bool isDone = false;
bool board[300][300];
int boardSize; 
pair<int, int> startPos, endPos; 

void solve() {
    queue<pair<pair<int, int>, int> >q;
    q.push({startPos, 0});
    board[startPos.first][startPos.second] = true;

    while (!q.empty()) {
        pair<int, int> pos = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (pos == endPos) {
            cout << cnt << endl;
            break;
        }

        for (int i = 0; i < 8; i++) {
            int newY = pos.first + dy[i];
            int newX = pos.second + dx[i];
            if (newY < 0 || newY > boardSize - 1|| newX < 0 || newX > boardSize - 1)
                continue;
            if (board[newY][newX])
                continue;
            
            board[newY][newX] = true;
            q.push({{newY, newX}, cnt + 1});
        }
    }
}

int main() {
    fastio;
    int N; cin >> N;
    while (N--) {
        cin >> boardSize;
        cin >> startPos.first >> startPos.second;
        cin >> endPos.first >> endPos.second;

        for (int i = 0; i < boardSize; i++) {
            for (int j = 0; j < boardSize; j++) {
                board[i][j] = false;
            }
        }
        solve();
    }
    return 0;
}