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

int main() {
    fastio;
    
    int N, K;
    stack<pair<char, int>>s;

    cin >> N >> K;
    string S; cin >> S;

    for (auto &c : S) {
        if (!s.empty() && s.top().x == c) {
            s.push({c, s.top().y+1});

            if (s.top().y == K) {
                for (int i = 0; i < K; i++) s.pop();
            }
        } else {
            s.push({c, 1});
        }
    }

    string a; 
    while (!s.empty()) a += s.top().x, s.pop();
    reverse(all(a));
    cout << a << endl;
    return 0;
}