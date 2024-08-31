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

char segment[7][21];

int main() {
    fastio;
    
    int T; cin >> T;
    while (T--) {
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 21; j++) {
                cin >> segment[i][j];
            }
        }

        int dx[] = {0, 5, 12, 17};
        int x[] = {0, 1, 1, 3, 4, 4, 6};
        int y[] = {1, 0, 3, 1, 0, 3, 1};

        for (int i = 0; i < 4; i++) {
            string str = "";
            for (int j = 0; j < 7; j++) {
                str += (segment[x[j]][dx[i] + y[j]] == 'X') ? '1' : '0';
            }

            if (str == "1110111") cout << 0;
            if (str == "0010010") cout << 1;
            if (str == "1011101") cout << 2;
            if (str == "1011011") cout << 3;
            if (str == "0111010") cout << 4;
            if (str == "1101011") cout << 5;
            if (str == "1101111") cout << 6;
            if (str == "1010010") cout << 7;
            if (str == "1111111") cout << 8;
            if (str == "1111011") cout << 9;
            if (i == 1) cout << ":";
        }
        cout << endl;
    }
    return 0;
}