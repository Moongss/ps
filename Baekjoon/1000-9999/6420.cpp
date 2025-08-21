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

string wtoi(string s) {
    __uint128_t tmp = 0;
    for (int i = 0; i < sz(s); i++) {
        tmp *= 26;
        tmp += (s[i] - 'a' + 1);
    }

    string ret;
    int cnt = 0;
    while (tmp) {
        if (cnt && cnt % 3 == 0) ret += ',';
        ret += tmp % 10 + '0';
        tmp /= 10;
        cnt++;
    }

    reverse(all(ret));
    return ret;
}

string itow(string n) {
    __uint128_t tmp = 0;
    for (int i = 0; i < sz(n); i++) {
        tmp *= 10;
        tmp += n[i] - '0';
    }

    string ret;
    while (tmp) {
        ret += (tmp - 1) % 26 + 'a';
        tmp = (tmp - 1) / 26;
    }

    reverse(all(ret));
    return ret;
}

int main() {
    fastio;

    while (true) {
        string s; cin >> s;
        string ret;
        if (s == "*") break;
        if (s[0] >= '0' && s[0] <= '9') ret = itow(s);
        else ret = s;

        cout << ret;
        for (int i = sz(ret); i < 22; i++) cout << ' ';
        cout << wtoi(ret) << endl;
    }
    return 0;
}