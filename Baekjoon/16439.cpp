#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, M;
int prefer[31][31];

int main() {
    fastio;
    
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> prefer[i][j];
        }
    }

    int result = 0;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= M; j++) {
            for (int k = 1; k <= M; k++) {
                int sum = 0;
                for (int l = 1; l <= N; l++) {
                    sum += max(prefer[l][i], max(prefer[l][j], prefer[l][k]));
                }
                result = max(result, sum);
            }
        }
    }
    cout << result << endl;
    return 0;
}