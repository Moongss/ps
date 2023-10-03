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
        ll AMax = -1, AMin = 1e+9 + 1, BMax = -1, BMin = 1e+9 + 1;

        for (int i = 0; i < n; i++) {
            ll tmp;
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
            ll tmp;
            std::cin >> tmp;
            BSum += tmp;
            if (tmp > BMax) {
                BMax = tmp;
            }
            if (tmp < BMin) {
                BMin = tmp;
            }
        }

        ll min = (AMin < BMin) ? AMin : BMin;
        ll max = (AMax > BMax) ? AMax : BMax;
        k--;
        if (AMin < BMax) {
            ASum = ASum - AMin + BMax;
            BSum = BSum - BMax + AMin;
        }

        ll result = ASum;
        if (k >= 1) {
            if (BMin < AMax) {
                result = ASum - min + max;
            }
        }
        
        if (k % 2 == 0) {
            if (AMin < BMax)
            result = ASum + min - max;
        }

        std::cout << result << std::endl;
    }
    return 0;
}