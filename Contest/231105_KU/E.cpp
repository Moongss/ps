#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

char ch[26] = {0, };
int main() {
    fastio;
    int N; cin >> N;
    string str; cin >> str;
    for (int i = 0; i < str.length() / 2; i++) {
        ch[str[i] - 'a']++;
        ch[str[str.length() - 1 - i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (ch[i] % 2 != 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}