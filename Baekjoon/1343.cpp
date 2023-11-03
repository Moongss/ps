#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int main() {
    fastio;
    string str; cin >> str;
    string result = "";
    int cnt = 0;

    for (auto ch : str) {
        if (ch == '.') {
            if (cnt % 2 != 0) {
                cout << -1 << endl;
                return 0;
            } else {
                for (int i = 0; i < cnt / 4; i++) {
                    result += "AAAA";
                }
                cnt %= 4;
                for (int i = 0; i < cnt / 2; i++) {
                    result += "BB";
                }
                cnt = 0;
            }
            result += ".";
        } else {
            cnt++;
        }
    }
    if (cnt) {
        if (cnt % 2 != 0) {
            cout << -1 << endl;
            return 0;
        } else {
            for (int i = 0; i < cnt / 4; i++) {
                result += "AAAA";
            }
            cnt %= 4;
            for (int i = 0; i < cnt / 2; i++) {
                result += "BB";
            }
            cnt = 0;
        }
    }
    cout << result << endl;
    return 0;
}