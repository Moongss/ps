#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int T, N;
int cnt[201];
int scoreCnt[201];
int sum[201][2];
vector<int> v;

int main() {
    fastio;
    
    cin >> T;
    while (T--) {
        cin >> N;
        memset(cnt, 0, sizeof(cnt));
        memset(sum, 0, sizeof(sum));
        memset(scoreCnt, 0, sizeof(scoreCnt));
        v.clear();

        for (int i = 1; i <= N; i++) {
            int x; cin >> x; v.push_back(x);
            cnt[x]++;
        }

        int score = 1;
        for (auto e : v) {
            if (cnt[e] == 6) {
                scoreCnt[e]++;
                if (scoreCnt[e] == 5)
                    sum[e][1] = score;
                else if (scoreCnt[e] < 5)
                    sum[e][0] += score;
                score++;
            }
        }

        int winTeam = 1;
        int winScore = 42424242;    
        for (int i = 1; i <= N; i++) {
            if (cnt[i] != 6) continue;
            if (sum[i][0] < winScore) {
                winScore = sum[i][0];
                winTeam = i;
            }
            else if (sum[i][0] == winScore) {
                if (sum[i][1] < sum[winTeam][1]) {
                    winTeam = i;
                }
            }
        }

        cout << winTeam << endl;
    }
    return 0;
}