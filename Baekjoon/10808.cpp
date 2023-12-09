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
    string str; cin >> str;
    int cnt[26] = {0, };

    for (int i = 0; i < str.size(); i++)
        cnt[str[i] - 'a']++;
    for (int i = 0; i < 26; i++)
        cout << cnt[i] << " ";
    return 0;
}