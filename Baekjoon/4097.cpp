#include <iostream>

using ll = long long;
int N;

int main() {
    while (true) {
        std::cin >> N;
        if (N == 0)
            break;

        ll result = -2500000001;
        ll sum = 0;
        for (int i = 0; i < N; i++) {
            ll num;
            std::cin >> num;
            sum += num;
            result = std::max(result, sum);
            if (sum < 0)
                sum = 0;
        }
        std::cout << result << std::endl;
    }

    return 0;
}