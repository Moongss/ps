#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())
#define sz(v) (int)v.size()
#define NO {cout << "NO" << endl; return;}
#define YES {cout << "YES" << endl; return;}

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int N;
int cnt;
int arr[100][100];
bool visited[100][100];
pii pos;

vector<pii> vv;
int dx[] = {1, 1, -1, -1};
int dy[] = {1, -1, 1, -1};
void solve() {
    queue<pii> q; q.push(pos);
    visited[pos.x][pos.y] = true;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (visited[nx][ny]) continue;

            visited[nx][ny] = true;
            q.push({nx, ny});
            if (arr[nx][ny] == 1) cnt++;
        }
    }
}

int main() {
    fastio;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {vv.push_back({i, j});}
            if (arr[i][j] == 2) pos = {i, j};
        }
    }
    solve();
    if (cnt == vv.size()) {
        sort(all(vv));
        int ret = 42424242;
        do {
            pii prv = pos;
            int dist = 0;
            for (auto &e : vv) {
                dist += max(abs(prv.x - e.x), abs(prv.y - e.y));
                prv = e;
            }
            ret = min(ret, dist);
        } while (next_permutation(all(vv)));
        cout << "Undertaker" << endl << ret << endl;
    } else {
        cout << "Shorei" << endl;
    }
    return 0;
}