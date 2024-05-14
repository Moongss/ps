#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int main() {
    fastio;

    int N; cin >> N;
    string result;
    while (N--) {
        string str; cin >> str;

        int cnt = 0;
        for (auto x : str) {
            if (x >= '0' && x <= '9') cnt++;
        }
        if (cnt == str.length()) continue;
        if (str.length() > 10) continue;

        int aCnt = 0;
        int Acnt = 0;
        for (auto x : str) {
            if (x >= 'A' && x <= 'Z') Acnt++;
            if (x >= 'a' && x <= 'z') aCnt++;
        }
        if (aCnt < Acnt) continue;

        result = str;
    }
    cout << result << endl;
    return 0;
}