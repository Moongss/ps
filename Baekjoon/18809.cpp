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

int arr[55][50];
int times[50][50];
pii visited[50][50];
bool visited2[50][50];

vector<pii> v;
vector<int> cv1;
vector<int> cv2;
vector<pair<char, pair<int, int>>> init;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int N, M, G, R;

int solve() {
    queue<pii> q;
    memset(times, 0, sizeof(times));
    memset(visited, 0, sizeof(visited));
    memset(visited2, 0, sizeof(visited2));
    for (auto &i : init) {
        if (i.x == 'G') visited[i.y.x][i.y.y].x = 1;
        else visited[i.y.x][i.y.y].y = 1;

        times[i.y.x][i.y.y] = 1;
        q.push({i.y});
    }

    int ret = 0;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        if (visited2[x][y]) continue;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (!arr[nx][ny]) continue;
            // if (visited[x][y].x && visited[nx][ny].x) continue;
            // if (visited[x][y].y && visited[nx][ny].y) continue;

            if (!times[nx][ny] || times[nx][ny] == times[x][y] + 1) {
                if (visited[x][y].x && !visited[nx][ny].x) {
                    visited[nx][ny].x = true;
                    times[nx][ny] = times[x][y] + 1;
                    if (visited[nx][ny].x && visited[nx][ny].y) {ret++; visited2[nx][ny] = true; }
                    else q.push({nx, ny});
                }
                if (visited[x][y].y && !visited[nx][ny].y) {
                    visited[nx][ny].y = true;
                    times[nx][ny] = times[x][y] + 1;
                    if (visited[nx][ny].x && visited[nx][ny].y) {ret++; visited2[nx][ny] = true;}
                    else q.push({nx, ny});
                }
            }
        }     
    }
    return ret;
}

int main() {
    fastio;
    
    cin >> N >> M >> G >> R;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) v.push_back({i, j});
        }
    }

    cv1.resize(v.size()); cv2.resize(G+R);
    for (int i = 0; i < v.size(); i++) {
        cv1[i] = (i < G+R) ? 1 : 0;
        if (i < G+R) cv2[i] = (i < G) ? 1 : 0;
    }
    sort(all(cv1)); sort(all(cv2));

    int ret = 0;
    do {
        sort(all(cv2));
        do {
            init.clear();
            vector<int> tmp; 
            for (int i = 0; i < cv1.size(); i++) {
                if (cv1[i]) tmp.push_back(i);
            }
            for (int i = 0; i < cv2.size(); i++) {
                if (cv2[i]) init.push_back({'G', v[tmp[i]]});
                else init.push_back({'R', v[tmp[i]]});
            }
            ret = max(ret, solve());
        } while (next_permutation(all(cv2)));
    } while (next_permutation(all(cv1)));

    cout << ret << endl;
    return 0;
}