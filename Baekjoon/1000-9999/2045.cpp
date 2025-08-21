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

int main() {
    fastio;
    
    int sum = 0;
    int arr[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3;j++) {
            cin >> arr[i][j];
            sum += arr[i][j];
        }
    }

    bool rf, cf;
    int rsum, csum, total = -1;
    for (int i = 0; i < 3; i++) {
        rsum = csum = 0;
        rf = cf = true;
        for (int j = 0; j < 3; j++) {
            rsum += arr[i][j];
            csum += arr[j][i];
            
            if (arr[i][j] == 0) rf = false;
            if (arr[j][i] == 0) cf = false;
        }
        if (rf) {total = rsum; break;}
        if (cf) {total = csum; break;}
    }

    int dr, ds;
    dr = ds = 0;
    rf = cf = true;
    for (int i = 0; i < 3; i++) {
        dr += arr[i][i];
        ds += arr[i][2 - i];

        if (arr[i][i] == 0) {rf = false;}
        if (arr[i][2 - i] == 0) {cf = false;}
    }
    if (rf) total = dr;
    if (cf) total = ds;

    if (!arr[0][0] && !arr[1][1] && !arr[2][2] ||
        !arr[0][2] && !arr[1][1] && !arr[2][0]) {
        total = sum / 2;
    }

    for (int l = 0; l < 2; l++) {
        for (int i = 0; i < 9; i++) {
            int x = i / 3;
            int y = i % 3;

            int cnt, check;
            cnt = rsum = 0;
            for (int j = 0; j < 3; j++) {
                if (!arr[x][j]) cnt++, check = j;
                else rsum += arr[x][j];
            }
            if (cnt == 1) arr[x][check] = total - rsum;

            cnt = csum = 0;
            for (int j = 0; j < 3; j++) {
                if (!arr[j][y]) cnt++, check = j;
                else csum += arr[j][y];
            }
            if (cnt == 1) arr[check][y] = total - csum;
        }
    }


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}