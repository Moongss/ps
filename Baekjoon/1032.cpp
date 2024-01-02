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
    
    int N; cin >> N;
    string result; cin >> result;

    for (int i = 0; i < N - 1; i++) {
        string s; cin >> s;
        for (int j = 0; j < s.size(); j++) {
            if (result[j] != s[j]) result[j] = '?';
        }
    }
    cout << result << endl;
    return 0;
}