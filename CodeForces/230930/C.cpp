#include <iostream>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    std::cin >> T;
    while (T--) {
        ll n, m;
        std::cin >> n >> m;

        if ((ll)n % (ll)m == 0) {
            std::cout << 0 << std::endl;
            continue;
        }

        ld temp = (ld)n / (ld)m;
        bool flag = true;
        while (true) {
            if (temp > n) {
                std::cout << -1 << std::endl;
                flag = false;
                break;
            }
            if (((ld)n - temp) < 1e-9) {
                break;
            } else {
                temp *= 2;
            }
        }

        ll cnt = 0;
        while (flag) {
            if (n == m) {
                std::cout << cnt << std::endl;
                break;
            }
            if (n > m) {
                n %= m;
            } else {
                cnt += n;
                n *= 2;
            }
        }
    }
    return 0;
}