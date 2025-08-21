#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int N, K, P;
deque<int> dq; 
vector<int> v;
int main() {
    fastio;
    
    cin >> N >> K >> P;
    for (int i = 1; i <= K; i++) {
        dq.push_back(i);
    }

    while (!dq.empty()) {
        for (int i = 0; i < N; i++) {
            int cur = dq.front(); 
            if (i == N - 1) v.push_back(cur);
            dq.pop_front();

            for (int j = 0; j < P; j++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
    }

    sort(v.begin(), v.end());
    for (auto x : v) {
        cout << x << endl;
    }
    return 0;
}