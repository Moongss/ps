#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_mset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, K, L;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int dir_pos = 0;

void rotate(char q) {
    if (q == 'L') {
        dir_pos = (dir_pos + 3) % 4;
    } else {
        dir_pos = (dir_pos + 1) % 4;
    }
}

pii head = {1, 1};
pii tail = {1, 1};
int arr[101][101];
bool apples[101][101];
char turn[10101];

int main() {
    fastio;
    
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        int x, y; cin >> x >> y;
        apples[x][y] = 1; // 사과
    }

    cin >> L;
    for (int i = 0; i < L; i++) {
        int x; char c;
        cin >> x >> c;
        turn[x] = c; // 방향 전환
    }

    int t = 0;
    bool isfinished = false;
    arr[head.x][head.y] = t+1;
    while (!isfinished) {
        t++;
        head.x += dx[dir_pos];
        head.y += dy[dir_pos];
        // cout << "dirpos : " << head.x << " " << head.y << endl;

        if (head.x < 1 || head.x > N || head.y < 1 || head.y > N ||
            arr[head.x][head.y] != 0) {
            isfinished = true;
            break;
        }
        arr[head.x][head.y] = t+1;

        // cout << "t : " << t << "=============" << endl;
        // for (int i = 1; i <= N; i++) {
        //     for (int j = 1; j <= N; j++) {
        //         cout << arr[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        if (apples[head.x][head.y]) {
            apples[head.x][head.y] = 0; // 사과 먹음
            // cout << "eat apple" << endl;
        } else {
            pii prev = tail;
            // cout << "tail : " << tail.x << " " << tail.y << endl;
            for (int i = 0; i < 4; i++) {
                int nx = tail.x + dx[i];
                int ny = tail.y + dy[i];
                if (nx < 1 || nx > N || ny < 1 || ny > N) {
                    continue;
                }
                // cout << "nx : " << nx << ", ny : " << ny << "arr[nx][ny] : " << arr[nx][ny] << endl;
                if (arr[nx][ny] - 1 == arr[tail.x][tail.y]) {
                    tail = {nx, ny};
                    break;
                }
            }
            arr[prev.x][prev.y] = 0;
        }
        if (turn[t]) rotate(turn[t]);

        // for (int i = 1; i <= N; i++) {
        //     for (int j = 1; j <= N; j++) {
        //         cout << arr[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "=================== " << endl;
    }
    cout << t << endl;
    return 0;
}