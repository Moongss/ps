#include <iostream>

using ll = long long;

ll K;
std::vector<ll> v;

int prime[45000] = {0, };

void primeSet() {
    for (int i = 2; i <= 45000; i++) {
        prime[i] = i;
    }
    
    for (int i = 2; i <= 45000; i++) {
        if (prime[i] == 0) continue;
        for (int j = i + i; j <= 45000; j += i) {
            prime[j] = 0;
        }
    }
}

int main() {
    primeSet();

    std::cin >> K;

    ll lo = 0;
    ll hi = 2e9;

    ll cnt = 0;
    for (ll i = 1; i <= 200; i++) {
        bool flag = true;
        ll sum = 0;
        for (ll j = 2; j * j <= i; j++) {
            if (prime[j] == 0) continue;
            if (i % (j * j) == 0) {
                flag = false;
                break;
            }

            std::cout << "i : " << i << ", j * j :  " << j * j<< std::endl;
            sum += i / (j * j);
        }
        if (flag) {
            cnt++;
            std::cout << "cnt : " << cnt << ", i : " << i << ", sum : " << sum << std::endl;
        }
    }
    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2;

        ll cnt = 0;
        for (ll i = 2; i * i <= mid; i++) {
            if (prime[i] == 0) continue;
            cnt += mid / (i * i);
        }

        std::cout << "mid : " << mid << ", cnt : " << cnt << std::endl;
        if (mid - cnt >= K) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    std::cout << hi << std::endl;
    return 0;
}