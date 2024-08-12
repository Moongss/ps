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

const ll inf = (1LL << 63) - 1;

int N, M;
int arr[2000][2000];
int pre[2000][2000];

int main() {
    fastio;
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string str; cin >> str;
        for (int j = 0; j < M; j++) {
            arr[i][j] = str[j] - '0';
            if (i != N - 1) arr[i + N][j] = arr[i][j];
            if (j != M - 1) arr[i][j + M] = arr[i][j];
            if (i != N - 1 && j != M - 1) arr[i + N][j + M] = arr[i][j];
        }
    }

    int ret = -1;
    for (int i = 1; i < 2 * N - 1; i++) {
        for (int j = 1; j < 2 * M - 1; j++) {
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
            if (arr[i - 1][j - 1] == arr[i - 1][j] &&
                arr[i - 1][j - 1] == arr[i][j - 1] &&
                arr[i - 1][j] == arr[i][j]) {
                pre[i][j]++;
            }

            if (i >= N - 1 && j >= M - 1) {
                ret = max(ret, pre[i][j] - pre[i - (N - 1)][j] - pre[i][j - (M - 1)] + pre[i - (N - 1)][j - (M - 1)]);
            }
        }
    }
    cout << ret << endl;
    return 0;
}