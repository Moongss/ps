#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, S;
int sum = 0;
int result = 0;
vector<int> v;
bool test[20];
int cnt = 0;
void solve(int idx) {
    if (idx == N) {
        if (sum == S && cnt) result++;
        return;
    }

    sum += v[idx]; cnt++;
    solve(idx + 1);
    sum -= v[idx]; cnt--;
    solve(idx + 1);
}
int main() {
    fastio;
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        v.push_back(tmp);
    }

    solve(0);
    cout << result << endl;
    return 0;
}