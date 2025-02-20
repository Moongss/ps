#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int n, m, k;

char plan[25][25];
bool visited[25][25];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

vector<int> rooms;

int solve(pii cur) {
    queue<pii> q;
    q.push(cur); visited[cur.x][cur.y] = true;

    int cnt = 0;
    while (!q.empty()) {
        pii c = q.front(); q.pop(); cnt++;

        for (int i = 0; i < 4; i++) {
            int nx = c.x + dx[i];
            int ny = c.y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (plan[nx][ny] == 'I') continue;
            if (visited[nx][ny]) continue;

            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    return cnt;
}
int main() {
    fastio;

    cin >> k;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> plan[i][j];
        }
    }

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (plan[i][j] == '.' && !visited[i][j]) {
                rooms.push_back(solve({i, j}));
            }
        }
    }
    sort(all(rooms)); reverse(all(rooms));

    int cnt = 0;
    for (auto &r : rooms) {
        if (k >= r) k -= r, cnt++;
        else break;
    }    

    cout << cnt << " room" << (cnt != 1 ? "s" : "") << ", " << k << " square metre(s) left over" << endl;
    return 0;
}