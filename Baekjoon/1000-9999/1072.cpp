#include <iostream>

using ll = long long;

ll X, Y;

int main() {
    std::cin >> X >> Y;
    ll Z = (100 * Y) / X;

    ll lo = -1, hi = 1e+10;
    ll result = -1;
    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2;
        ll newZ = (100 * (Y + mid)) / (X + mid);
        if (newZ > Z) {
            hi = mid;
            result = mid;
        } else {
            lo = mid;
        }
    }
    std::cout << result << std::endl;
    return 0;
}