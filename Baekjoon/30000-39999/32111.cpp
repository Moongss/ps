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

char ans[505050];
int main() {
    fastio;
    
    int N; cin >> N;
    string str; cin >> str;

    int Ocnt = 0;
    int s = N + 1, e = -1;
    for (int i = 0; i < N; i++) {
        ans[i] = '-';
        if (str[i] == 'O') {
            ans[i] = '+'; Ocnt++;
            s = min(s, i);
            e = max(e, i);
        }
    }

    if (Ocnt == 0 || Ocnt == N) {
        cout << "YES" << endl;
        for (int i = 0; i < N; i++) {
            cout << ans[i];
        }
        cout << endl;
        return 0;
    }

    for (int i = s; i < e; i++) {
        int cnt = 0;
        while (str[i] == 'X' && i < e) {
            cnt++;
            i++;
        }

        if (cnt) {
            if (cnt % 2 == 0) {cout << "NO" << endl; return 0;}
            else {
                for (int j = 0; j < cnt / 2; j++) {
                    ans[(i - cnt + j) % N] = '+';
                }
            }
        }
    }

    int cnt = (N - e - 1) + (s);
    if (cnt) {
        if (cnt % 2 == 0) {cout << "NO" << endl; return 0;}
        else {
            for (int j = 0; j < cnt / 2; j++) {
                ans[(e + 1 + j) % N] = '+';
            }
        }
    } 

    cout << "YES" << endl;
    for (int i = 0; i < N; i++) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}