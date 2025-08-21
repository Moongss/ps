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

vector<pair<string, pair<string, string>>> v;

int main() {
    fastio;
    
    while (true) {
        string cmd; cin >> cmd;
        if (cmd == "EXIT") {cout << "EXIT" << endl; break;}
        if (cmd == "WRITE") {
            string src, dst, _; cin >> src >> _ >> dst;

            for (auto &e : v) {
                if (e.x == "WRITE") {
                    if (e.y.y == src ||
                        e.y.y == dst ||
                        e.y.x == dst) {
                        cout << "WAIT" << endl;
                        v.clear();
                        break;
                    }
                } else {
                    if (e.y.y == dst) {
                        cout << "WAIT" << endl;
                        v.clear();
                        break;
                    }
                }
            }
            cout << "WRITE " << src << " TO " << dst << endl;
            v.push_back({"WRITE", {src, dst}});
        } else {
            string src; cin >> src;
            for (auto &e : v) {
                if (e.x == "WRITE" && e.y.y == src) {
                    cout << "WAIT" << endl;
                    v.clear();
                    break;
                }
            }
            cout << "READ " << src << endl;
            v.push_back({"READ", {src, src}});
        }
    }
    return 0;
}