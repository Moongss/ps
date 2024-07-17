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
map<int, string> m2;
int main() {
    fastio;

    m["063"] = 0; m2[0] = "063";
    m["010"] = 1; m2[1] = "010";
    m["093"] = 2; m2[2] = "093";
    m["079"] = 3; m2[3] = "079";
    m["106"] = 4; m2[4] = "106";
    m["103"] = 5; m2[5] = "103";
    m["119"] = 6; m2[6] = "119";
    m["011"] = 7; m2[7] = "011";
    m["127"] = 8; m2[8] = "127";
    m["107"] = 9; m2[9] = "107";

    while (true) {
        string str; cin >> str;
        if (str == "BYE") break;

        int l, r, sum; l = r = sum = 0;
        int cnt = 0;
        string tmp = "";
        for (int i = 0; i < sz(str); i++) {
            if (str[i] == '+') {
                l = sum; 
                sum = 0;
            }
            else if (str[i] == '=') {
                r = sum;
                tmp = to_string(l + r);
                break;
            }
            else {
                cnt++;
                tmp += str[i];
                if (cnt == 3) {
                    sum = sum * 10 + m[tmp];
                    tmp = ""; cnt = 0;
                }
            }
        }

        cout << str;
        for (int i = 0; i < sz(tmp); i++) {
            cout << m2[tmp[i] - '0'];
        }
        cout << endl;
    }
    return 0;
}