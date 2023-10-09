#include <iostream>
#include <algorithm>
#include <vector>
using ll = long long;

ll N, A, B;
ll btn[100000];
std::vector<ll> result;
int main() {
    std::cin >> N >> A >> B;

    ll targetMask = 0;
    ll tmp = B;
    ll cnt = 0;
    while (tmp > 0) {
        if (tmp % 2 == 1)
            targetMask |= (1 << cnt);
        tmp /= 2;
        cnt++;
    }

    ll btn_idx = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> btn[i];
    }

    ll startMask = 0;
    tmp = A;
    cnt = 0;
    while (tmp > 0) {
        if (tmp % 2 == 1)
            startMask |= (1 << cnt);
        tmp /= 2;
        cnt++;
    }
    while (btn_idx < N)
    {
        ll currentMask = 0;
        ll cnt = 0;
        ll current = btn[btn_idx];
        while (current > 0) {
            if (current % 2 == 1)
                currentMask |= (1 << cnt);
            current /= 2;
            cnt++;
        }

        if ((currentMask & startMask) == currentMask) {
            btn_idx++;
            continue;
        }

        if ((currentMask & targetMask) == currentMask) {
            startMask |= currentMask;
            result.push_back(btn_idx + 1);
            btn_idx++;
        } else {
            btn_idx++;
        }
    }
    if (startMask == targetMask && result.size() <= 100) {
        std::cout << result.size() << std::endl;
        for (int i = 0; i < result.size(); i++) {
            std::cout << result[i] << " ";
        }
        return 0;
    }
    std::cout << -1 << std::endl;
    return 0;
}