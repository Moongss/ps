#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int cnt[26];
int main() {
    fastio;
 

    string s;
    while (cin >> s) {
        for (char c : s) cnt[c - 'a']++;
    }

    int max = 0;
    for (int i = 0; i < 26; i++) if (cnt[i] > max) max = cnt[i];
    for (int i = 0; i < 26; i++) if (cnt[i] == max) cout << (char)(i + 'a');
    return 0;
}