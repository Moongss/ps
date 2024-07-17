#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int N;
int ans[100001];
string str = "abcdefghijklmnopqrstuvwxyz";
// abcdefghijklm nopqrstuvwxyz
// abcdefg hijklm nopqrst uvwxyz
// abcd hij nopq uvw
// ab e hk no r u x
// a c f i l n p s v y

int main() {
    fastio;
    int x, n;

    cout << "? " << str << endl << flush;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> x;

    cout << "? " << "abcdefghijklm" << endl << flush;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        ans[x] += 13;
    }

    cout << "? " << "abcdefgnopqrst" << endl << flush;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        ans[x] += 6;
    }

    cout << "? " << "abcdhijnopquvw" << endl << flush;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        ans[x] += 3;
    }

    cout << "? " << "abehknorux" << endl << flush;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        ans[x] += 2;
    }

    cout << "? " << "acfilnpsvy" << endl << flush;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        ans[x] += 1;
    }

    cout << "! ";
    for (int i = 1; i <= N; i++) cout << str[25 - ans[i]];
    cout << flush;
    return 0;
}