#include <iostream>

using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    std::cin >> t;
    while (t--) {
        ll n, m, k;
        std::cin >> n >> m >> k;

        ll ASum = 0, BSum = 0;
        ll AMax = -1, AMin = 4242424242, BMax = -1, BMin = 4242424242;
        for (int i = 0; i < n; i++) {
            int tmp;
            std::cin >> tmp;
            ASum += tmp;
            if (tmp > AMax) {
                AMax = tmp;
            }
            if (tmp < AMin) {
                AMin = tmp;
            }
        }
        for (int i = 0; i < m; i++) {
            int tmp;
            std::cin >> tmp;
            BSum += tmp;
            B.push_back(tmp);
            if (tmp > BMax) {
                BMax = tmp;
            }
            if (tmp < BMin) {
                BMin = tmp;
            }
        }

        ll result = ASum;
        if (k % 2 == 1) {
            if (AMin < BMax)
                result = ASum - AMin + BMax;
        }

        std::cout << result << std::endl;
    }
    return 0;
}