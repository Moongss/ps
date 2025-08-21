#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int pre[200000][26];
int N;
string str;

int main() {
    fastio;
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        if (i == 0) pre[0][str[i] - 'a'] = 1;
        else {
            for (int j = 0; j < 26; j++) {
                pre[i][j] = pre[i - 1][j];
                if (str[i] - 'a' == j)
                    pre[i][j]++;
            }
        }
    }

    cin >> N;
    while (N--) {
        char ch; int l, r;
        cin >> ch >> l >> r;
        if (l == 0)
            cout << pre[r][ch - 'a'] << endl;
        else
            cout << pre[r][ch - 'a'] - pre[l - 1][ch - 'a'] << endl;
    }
    return 0;
}