#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    string source, target;
    getline(cin, source);
    getline(cin, target);

    int result = 0;
    int idx = 0;

    if (source.length() < target.length()) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < source.length() - target.length() + 1; i++) {
        if (source[i] == target[0]) {
            bool flag = true;
            for (int j = 0; j < target.length(); j++) {
                if (source[i + j] != target[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                result++;
                i += target.length() - 1;
            }
        }
    }
    cout << result << endl;
    return 0;
}