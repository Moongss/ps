#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())
#define sz(v) (int)v.size()
#define NO {cout << "NO" << endl; return;}
#define YES {cout << "YES" << endl; return;}

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int inf = 0x3f3f3f3f;

int N, sum;
int arr[22][22];
int pre[22][22];
int dp[22][22][40404];


int solve(int x, int y, int cur) {
    if (y == N) return dp[x][y][cur] = abs(sum - 2 * cur);
    if (dp[x][y][cur] != inf) return dp[x][y][cur];

    for (int i = x; i <= N; i++) {
        int ret = solve(i, y + 1, cur + pre[i][y + 1]);
        dp[x][y][cur] = min(dp[x][y][cur], ret);
    }
    return dp[x][y][cur];
}

int main() {
    fastio;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int newI = N - i + 1;
            cin >> arr[newI][j];
            sum += arr[newI][j];
        }   
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            pre[j][i] = pre[j - 1][i] + arr[j][i];
        }
    }

    memset(dp, 0x3f, sizeof(dp));
    solve(0, 0, 0);

    pii prv = {0, 0};
    int target = dp[0][0][0];
    int utSum = 0; //upperTriangle
    vector<int> ret;
    for (int i = 0; i <= N; i++) {
        if (i == N) break;
        for (int x = prv.x; x <= N; x++) {
            if (target == dp[x][prv.y + 1][utSum + pre[x][prv.y + 1]]) {
                ret.push_back(x);
                target = dp[x][prv.y + 1][utSum + pre[x][prv.y + 1]];
                utSum += pre[x][prv.y + 1];
                prv = {x, prv.y + 1};
                break;
            }
        }
    }
    cout << abs(sum - 2 * utSum) << endl;
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << " ";
    }
    cout << endl;
    return 0;
}