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

int arr[11];
char mat[11][11];
int N;
int pre[11];
void solve(int cur) {
    if (cur > N) {
        for (int i = 1; i <= N; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        exit(0);
    }

    for (int i = -10; i <= 10; i++) {
        arr[cur] = i;
        
        bool f = true;
        for (int j = 1; j <= cur; j++) {
            int tmp = 0;
            for (int k = j; k <= cur; k++) {
                tmp += arr[k];
            }

            if (tmp > 0 && mat[j][cur] == '+') continue;
            if (tmp < 0 && mat[j][cur] == '-') continue;
            if (tmp == 0 && mat[j][cur] == '0') continue;
            f = false;
            break;
        }

        if (f) solve(cur + 1);
    }
}

int main() {
    fastio;

    cin >> N; cin.clear();
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            cin >> mat[i][j];
        }
    }
    
    solve(1);
    return 0;
}