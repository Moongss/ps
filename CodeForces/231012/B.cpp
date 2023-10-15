#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        std::cin >> a >> b >> c;

        ll sum = 0;
        if (a >= c && b >= c) {
            if (a % c == 0 && b % c == 0) {
                sum += a / c + b / c - 2;
            } else {
                std::cout << "NO" << std::endl;
                continue;
            }
        } else if (a >= b && c >= b) {
            if (a % b == 0 && c % b == 0) {
                sum += a / b + c / b - 2;
            } else {
                std::cout << "NO" << std::endl;
                continue;
            }
        } else if (b >= a && c >= a) {
            if (b % a == 0 && c % a == 0) {
                sum += b / a + c / a - 2;
            } else {
                std::cout << "NO" << std::endl;
                continue;
            }
        }

        if (sum <= 3)
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;
    }
    return 0;
}