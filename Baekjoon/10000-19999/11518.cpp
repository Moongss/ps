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

map<char, string> ctos;
map<string, char> stoc;
map<string, string> m;
int main() {
    fastio;
    
    for (int i = 0; i < 26; i++) {
        char ch; string str; cin >> ch >> str;
        ctos[ch] = str;
        stoc[str] = ch;
    }

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        string str; cin >> str;
        string tmp = "";
        for (auto &c : str) {
            tmp += ctos[c];
        }
        m[tmp] = str;
    }

    vector<string> result;
    while (true) {
        cin >> N;
        if (!N) break;

        bool f = true; result.clear();
        string wrong;
        for (int i = 0; i < N; i++) {
            string str; cin >> str;

            if (f) {
                if (m.find(str) == m.end()) {
                    f = false;
                    wrong = str;
                }
                else result.push_back(m[str]);
            }
        }

        if (f) {
            for (auto &x : result) {
                cout << x << " ";
            }
            cout << endl;
        } else {
            cout << wrong << " not in dictionary." << endl;
        }
    }
    return 0;
}