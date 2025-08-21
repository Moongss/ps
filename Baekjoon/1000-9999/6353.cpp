#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int main() {
    fastio;
    
    while (true) {
        int a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
        if (a + b + c + d + e + f == 0) break;

        ll sum = 0;
        if (f) sum += f;
        if (e) {
            while (e--) {
                if (a >= 11) a -= 11;
                else a = 0;
                sum++;
            }
        }
        if (d) {
            while (d--) {
                if (b >= 5) b -= 5;
                else {
                    int tmp = 36 - 16 - b * 4; b = 0;
                    if (a >= tmp) a -= tmp;
                    else a = 0;
                }
                sum++;
            }
        }
        if (c) {
            while (c) {
                if (c >= 4) {
                    c -= 4;
                    sum++;
                }
                else if (c == 3) {
                    c -= 3;
                    if (b) {
                        b--;
                        if (a >= 5) a -= 5;
                        else a = 0;
                    }
                    else {
                        if (a >= 9) a -= 9;
                        else a = 0;
                    }
                    sum++;
                }
                else if (c == 2) {
                    c -= 2;
                    if (b) {
                        int tmp = (b >= 3) ? 18 - 4 * 3 : 18 - 4 * b;
                        if (b >= 3) b -= 3;
                        else b = 0;

                        if (a >= tmp) a -= tmp;
                        else a = 0;
                    }
                    else {
                        if (a >= 18) a -= 18;
                        else a = 0;
                    }
                    sum++;
                } else {
                    c--;
                    if (b) {
                        int tmp = (b >= 5) ? 27 - 4 * 5 : 27 - 4 * b;
                        if (b >= 5) b -= 5;
                        else b = 0;

                        if (a >= tmp) a -= tmp;
                        else a = 0;
                    }
                    else {
                        if (a >= 27) a -= 27;
                        else a = 0;
                    }
                    sum++;
                }
            }
        }
        if (b) {
            // cout << "b : " << b << " " << a << endl;
            while (b) {
                int tmp = (b >= 9) ? 0 : 36 - 4 * b;
                if (b >= 9) b -= 9;
                else b = 0;

                if (a >= tmp) a -= tmp;
                else a = 0;
                sum++;
            }
        }
        if (a) {
            sum += (a / 36) + ((a % 36) ? 1 : 0);
        }

        cout << sum << endl;
    }
    return 0;
}
