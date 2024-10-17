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
#define sz(v) (int)v.size()

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_mset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

pair<bool, bool> visited[12][12];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int N; 
bool validate(int x) {
    if (x >= 1 && x <= N) return true;
    return false;
}

int main() {
    // fastio;

    cin >> N;
    string str; cin >> str;

    pii cur = {1, 1};
    for (auto &e : str) {
        if (e == 'D' && validate(cur.x + 1)) {cur.x++; visited[cur.x][cur.y].x = visited[cur.x - 1][cur.y].x = true;}
        if (e == 'U' && validate(cur.x - 1)) {cur.x--; visited[cur.x][cur.y].x = visited[cur.x + 1][cur.y].x = true;}
        if (e == 'R' && validate(cur.y + 1)) {cur.y++; visited[cur.x][cur.y].y = visited[cur.x][cur.y - 1].y = true;}
        if (e == 'L' && validate(cur.y - 1)) {cur.y--; visited[cur.x][cur.y].y = visited[cur.x][cur.y + 1].y = true;}
    }


    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            auto [x, y] = visited[i][j];
            if (x && y) cout << "+";
            else if (x) cout << "|";
            else if (y) cout << "-";
            else cout << ".";
        }
        cout << endl;
    }
 
    return 0;
}