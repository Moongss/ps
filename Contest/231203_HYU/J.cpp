#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    fastio;
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        string t; cin >> t;

        int pos = 0;
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == 'x' || s[j] == 'X') {
                pos = j;
                break;
            }
        }

        if ('a' <= t[pos] && t[pos] <= 'z')
            t[pos] = t[pos] - 'a' + 'A';
        cout << t[pos];
    }
    cout << endl;
    return 0;
}