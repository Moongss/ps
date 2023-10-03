#include <iostream>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    std::cin >> T;
    while (T--) {
        ll a, b, n;
        ll result = 0;
        std::cin >> a >> b >> n;

        if (b > 1)
            result += b - 1;
        b = 1;
        while (n--) {
            ll tmp;
            std::cin >> tmp;
            b = std::min(b + tmp, a);
            result += b - 1;
            b = 1;
        }
        result++;
        std::cout << result << std::endl;
    }
    return 0;
}