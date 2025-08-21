#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N;
stack<pii> s;

int main() {
    fastio;
    cin >> N;

    ll cnt = 0;
    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        int curCnt = 1;
        while (!s.empty() && s.top().first < tmp) {
            cnt += s.top().second;
            s.pop();
        }
        if (!s.empty()) {
            auto [val, elemCnt] = s.top();
            if (val > tmp) cnt++;
            else {
                curCnt = elemCnt + 1;
                cnt += elemCnt;
                s.pop();
                if (!s.empty()) cnt++; //s.top() > tmp
            }
        }
        s.push({tmp, curCnt});
    }
    cout << cnt << endl;
    return 0;
}