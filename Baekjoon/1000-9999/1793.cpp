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

string dp[250];
int n;

string add(string &a, string &b) {
    reverse(all(a));
    reverse(all(b));

    string ret = "";
    int carry = 0, sum = 0;
    int mmin = min(a.length(), b.length());
    int mmax = max(a.length(), b.length());
    for (int i = 0; i < mmax; i++) {
        if (i < mmin) {
            int aa = a[i] - '0';
            int bb = b[i] - '0';
            sum = aa + bb + carry;
        } else {
            int ab = (a.length() > b.length() ? a[i] - '0' : b[i] - '0');
            sum = ab + carry;
        }

        if (sum >= 10) carry = 1;
        else carry = 0;

        ret += (sum % 10) + '0';
    }
    if (carry) ret += "1";

    reverse(all(a)); reverse(all(b));
    reverse(all(ret));
    return ret;
}

int main() {
    fastio;
    
    dp[0] = dp[1] = "1";
    for (int i = 2; i <= 250; i++) {
        dp[i] = add(dp[i - 1], dp[i - 2]);
        dp[i] = add(dp[i], dp[i - 2]);
    }

    while (cin >> n) cout << dp[n] << endl;
    return 0;
}