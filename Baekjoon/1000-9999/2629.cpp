#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, M;
vector<int> v;
bool dp[31][15001];

void init(int i, int sum) {
    if (i > N || dp[i][sum]) return;
    dp[i][sum] = true;
    init(i + 1, sum + v[i]);
    init(i + 1, sum);
    init(i + 1, abs(sum - v[i]));
}

int main() {
    fastio;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        v.push_back(tmp);
    }

    init(0, 0);
    cin >> M;
    for (int i = 0; i < M; i++) {
        int target; cin >> target;
        if (target > 15000) cout << "N";
        else if (dp[N][target]) cout << "Y";
        else cout << "N";
        cout << " ";
    }
    cout << endl;
    return 0;
}