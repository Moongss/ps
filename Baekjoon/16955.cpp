#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

char arr[10][10];

bool solve(int x, int y) {
    int cnt;
    bool f;

    for (int i = 0; i < 5; i++) {
        cnt = 0, f = true;
        for (int j = 0; j < 5; j++) {
            if (arr[x+i][y+j] == 'O') {f = false; break;}
            if (arr[x+i][y+j] == 'X') cnt++;
        }
        if (f && cnt >= 4) return true;
    }

    for (int i = 0; i < 5; i++) {
        cnt = 0, f = true;
        for (int j = 0; j < 5; j++) {
            if (arr[x+j][y+i] == 'O') {f = false; break;}
            if (arr[x+j][y+i] == 'X') cnt++;
        }
        if (f && cnt >= 4) return true;
    }

    cnt = 0, f = true;
    for (int i = 0; i < 5; i++) {
        if (arr[x+i][y+i] == 'O') {f = false; break;}
        if (arr[x+i][y+i] == 'X') cnt++;
    }
    if (f && cnt >= 4) return true;


    f = true;
    cnt = 0; y += 4;
    for (int i = 0; i < 5; i++) {

        if (arr[x+i][y-i] == 'O') {f = false; break;}
        if (arr[x+i][y-i] == 'X') cnt++;
    }
    if (f && cnt >= 4) return true;

    return false;
}

int main() {
    fastio;
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (solve(i, j)) {
                cout << 1 << endl;
                return 0;
            }
        }
    }
    cout << 0 << endl;
    return 0;
}