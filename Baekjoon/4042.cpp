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

char arr[101][101];
vector<pii> vv;

int main() {
    fastio;
    
    int t = 0;
    while (true) {
        vv.clear(); memset(arr, 0, sizeof(arr));
        int v, o, m; cin >> v >> o >> m;
        if (v == 0 && o == 0 && m == 0) break;

        vv.resize(v); for (auto &e : vv) cin >> e.y >> e.x;
        for (int i = 0; i < o; i++) {int x, y; cin >> y >> x; arr[x][y] = 'm';}
        for (int i = 0; i < m; i++) {
            char s; int x1, x2, y1, y2; 
            cin >> s >> y1 >> x1 >> y2 >> x2;

            // if (s == 'E') s = 'W';
            // else if (s == 'W') s = 'E';
            // else if (s == 'N') s = 'S';
            // else if (s == 'S') s = 'N';
            
            if (x1 == x2) {
                if (y1 > y2) swap(y1, y2);
                for (int j = y1; j <= y2; j++) arr[x1][j] = s;
            }
            if (y1 == y2) {
                if (x1 > x2) swap(x1, x2);
                for (int j = x1; j <= x2; j++) arr[j][y1] = s;
            }
        }

        // for (int i = 0; i < 8; i++) {
        //     for (int j = 0; j < 8; j++) {
        //         if (!arr[i][j]) cout << "* ";
        //         else cout << arr[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        bool f = false;
        t++; cout << "Case " << t << ":" << endl;
        for (int i = 0; i < vv.size() && !f; i++) {
            auto [ex, ey] = vv[i];
            for (int j = ey; j >= 0 && !f; j--) {
                if (!arr[ex][j]) continue;
                if (arr[ex][j] == 'E') {f = true; break;}
                else break;
            }
            for (int j = ex; j >= 0 && !f; j--) {
                if (!arr[j][ey]) continue;
                if (arr[j][ey] == 'N') {f = true; break;}
                else break;
            }
            for (int j = ex; j <= 100 && !f; j++) {
                if (!arr[j][ey]) continue;
                if (arr[j][ey] == 'S') {f = true; break;}
                else break;
            }
            for (int j = ey; j <= 100 && !f; j++) {
                if (!arr[ex][j]) continue;
                if (arr[ex][j] == 'W') {f = true; break;}
                else break;
            }
        }

        if (!f) cout << "none" << endl;
        else {
            for (int i = 0; i < vv.size(); i++) {
                auto [ex, ey] = vv[i];
                string ret = "";
                for (int j = ey; j <= 100; j++) {
                    if (!arr[ex][j]) continue;
                    if (arr[ex][j] == 'W') {ret += "east "; break;}
                    else break;
                }
                for (int j = ex; j <= 100; j++) {
                    if (!arr[j][ey]) continue;
                    if (arr[j][ey] == 'S') {ret += "north "; break;}
                    else break;
                }
                for (int j = ex; j >= 0; j--) {
                    if (!arr[j][ey]) continue;
                    if (arr[j][ey] == 'N') {ret += "south "; break;}
                    else break;
                }
                for (int j = ey; j >= 0; j--) {
                    if (!arr[ex][j]) continue;
                    if (arr[ex][j] == 'E') {ret += "west "; break;}
                    else break;
                }

                if (ret.length()) cout << "vampire " << i + 1 << " " << ret << endl;
            }
        }
    }

    return 0;
}