#include <iostream>
#include <algorithm>

using ll = long long;
int main() {
    int N;
    ll x1, x2, y1, y2;

    x1 = y1 = 10001;
    x2 = y2 = -10001;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        ll a, b;
        std::cin >> a >> b;

        x1 = std::min(x1, a);
        y1 = std::min(y1, b);
        x2 = std::max(x2, a);
        y2 = std::max(y2, b);
    }

    std::cout << (x2 - x1) * (y2 - y1) << std::endl;
    return 0;
}