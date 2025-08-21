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

string str;
string pattern = "";

vector<char> cv;
vector<int> iv;
int main() {
    fastio;
    
    cin >> str;

    char ch = str[0];
    for (auto &c : str) {
        if (c == ch) {pattern += ch;}
        else break;
    }
    iv.push_back(pattern.length());
    cv.push_back(ch);

    while (pattern.length() < str.length()) {
        int idx = pattern.length();
        char ch = str[idx];

        string prev = pattern;
        int tmp = 0;
        int cnt = 0;
        while (tmp < str.length()) {
            tmp += prev.length();
            if (ch != str[tmp]) break;
            cnt++; tmp++;
        }

        for (int i = 0; i < cnt; i++) {
            pattern += ch;
            pattern += prev;
        }

        iv.push_back(cnt);
        cv.push_back(ch);
    }

    for (auto &c: cv) cout << c; cout << endl;
    for (auto &c: iv) cout << c << " "; cout << endl;
    return 0;
}