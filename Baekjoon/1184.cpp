#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_mset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N; 
int arr[51][51];
int pre[51][51];

int main() {
    fastio;
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            pre[i][j] += pre[i][j-1]+arr[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            pre[j][i] += pre[j-1][i];
        }
    }
    
    int cnt = 0;
    int tmp = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            pii A = {i, j};

            for (int k = i; k <= N; k++) {
                for (int l = j; l <= N; l++) {
                    pii B = {k, l};

                    for (int m = k + 1; m <= N; m++) {
                        for (int n = l + 1; n <= N; n++) {
                            pii C = {m, n};
                            tmp++;
                            int areaA = pre[B.x][B.y] - pre[B.x][A.y-1] - pre[A.x-1][B.y] + pre[A.x-1][A.y-1];
                            int areaD = pre[C.x][C.y] - pre[C.x][B.y] - pre[B.x][C.y] + pre[B.x][B.y];

                            int areaB = pre[B.x][C.y] - pre[A.x-1][C.y] - pre[B.x][B.y] + pre[A.x-1][B.y];
                            int areaC = pre[C.x][B.y] - pre[C.x][A.y-1] - pre[B.x][B.y] + pre[B.x][A.y-1];

                            if (areaA == areaD) cnt++;
                            if (areaB == areaC) cnt++;
                        }
                    }
                }
            }
        }
    }
    cout << cnt << endl;
    cout << tmp << endl;
    return 0;
}