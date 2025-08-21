#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

bool flag[26];
int main() {
    fastio;
    string str; cin >> str;

    for (auto x : str) {
        if (flag[x - 'a']) {cout << -1 << endl; return 0;}
        else flag[x - 'a'] = true;
    }

    if (str.length() == 26) {
        if (str == "zyxwvutsrqponmlkjihgfedcba") {
            cout << -1 << endl;
            return 0;
        }
        for (int i = 25; i > 0; i--) {
            for (int j = str[i] + 1; j <= 'z'; j++) {
                bool tmp = true;
                for (int k = 0; k < i; k++) {
                    if (str[k] == j) {
                        tmp = false;
                        break;                        
                    }
                }

                if (tmp) {
                    for (int k = 0; k < i; k++) {
                        cout << str[k];
                    }
                    cout << (char)j << endl;
                    return 0;
                }
            }
        }
    } else {
        for (int i = 0; i < 26; i++) {
            if (!flag[i]) {
                cout << str << (char)(i + 'a') << endl;
                return 0;
            }
        }
    }


    return 0;
}