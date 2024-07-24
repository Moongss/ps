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

map<string, int> m;
int main() {
    fastio;
    
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        string convert = "";
        for (auto &x : s) {
            if (convert.length() == 3) convert += '-';
            if (x == '-' || x == 'Q' || x == 'Z') continue;
            if ('A' <= x && x <= 'C') convert += '2';
            else if ('D' <= x && x <= 'F') convert += '3';
            else if ('G' <= x && x <= 'I') convert += '4';
            else if ('J' <= x && x <= 'L') convert += '5';
            else if ('M' <= x && x <= 'O') convert += '6';
            else if ('P' <= x && x <= 'S') convert += '7';
            else if ('T' <= x && x <= 'V') convert += '8';
            else if ('W' <= x && x <= 'Y') convert += '9';
            else convert += x;
        }
        m[convert]++;
    }

    bool f = false;
    for (auto &x : m) {
        if (x.y > 1) {
            cout << x.x << " " << x.y << endl;
            f = true;
        }
    }
    if (!f) {
        cout << "No duplicates." << endl;
    }
    return 0;
}