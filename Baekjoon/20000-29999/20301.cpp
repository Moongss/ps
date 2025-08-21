#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int N, M, K;
deque<int> dq;

int main() {
    fastio;
    
    cin >> N >> K >> M;

    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= N; i++) dq.push_back(i);
    
    while (!dq.empty()) {
        cnt1++;
        if (cnt1 == K) {
            if ((cnt2 / M) % 2 != 0) {
                cout << dq.back() << endl;
                dq.pop_back();
            } else {
                cout << dq.front() << endl;
                dq.pop_front();
            }
            cnt1 = 0;
            cnt2++;
        } else {
            if ((cnt2 / M) % 2 != 0) {
                dq.push_front(dq.back());
                dq.pop_back();
            } else {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
    }
    return 0;
}