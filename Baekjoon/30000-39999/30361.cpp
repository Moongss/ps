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

const ll mod = 998244353;
const ll inf = (1LL << 63) - 1;

int pre[100001];
int main() {
    // fastio;
    
    int T; cin >> T;
    while (T--) {
        int N, K; cin >> N >> K;

        for (int i = 1; i <= N; i++) {
            vector<int> v;
            for (int j = 1; j <= N; j++) {
                if (j <= i) v.push_back(1);
                else v.push_back(0);
            }


            sort(all(v));
            // for (int a = 1; a <= N; a++) {
            //     cout << "K : " << a << ", ";

                int sum = 0;
                do {   
                    for (int j = 0; j < N; j++) {
                        cout << v[j];
                    }
                    pre[0] = 0;
                    for (int j = 1; j <= N; j++) {
                        pre[j] = pre[j - 1] + v[j - 1];
                    }

                    int cnt = 0;
                    for (int l = 1; l <= N; l++) {
                        for (int k = 1; k <= N; k++) {
                            if ((pre[k] - pre[l - 1]) % 2 == 1) {
                                cnt++;
                            }
                        }
                    }

                    cout << ": " <<  cnt << " ";
                    cout << endl;
                } while (next_permutation(all(v)));
            // }
        }
    }
    return 0;
}