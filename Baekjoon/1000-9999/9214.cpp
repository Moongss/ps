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
    
    string N;
    string tmp;
    int idx = 0;
    while (1) {
        idx++;
        cin >> N;
        if (N == "0") break;

        tmp = N;
        while (1) {
            string result = "";
            for (int i = 0; i < tmp.length(); i += 2) {
                int x = tmp[i] - '0';
                for (int j = 0; j < x; j++) {
                    result += tmp[i + 1];
                }
            }
            if (result.length() % 2 != 0) {
                cout << result << endl;
                break;
            }
            else if (result == N) {
                cout << result << endl;
                break;
            }
            tmp = result;
        }

    }
    return 0;
}