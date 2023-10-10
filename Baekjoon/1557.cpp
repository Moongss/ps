#include <iostream>
#include <algorithm>
#include <vector>
using ll = long long;

ll K;

int prime[45000] = {0, };
std::vector<std::pair<int, ll> > v;

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

    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2;

        ll cnt = 0;
        v.clear();
        for (ll i = 2; i * i <= mid; i++) {
            if (prime[i] == 0) continue;
            cnt += mid / (i * i);
            v.push_back(std::make_pair(i, mid / (i * i)));
        }

        std::cout << "====================" << std::endl;
        std::cout << "mid : " << mid << ", cnt : " << cnt << std::endl;
        // for (int i = 0; i < v.size(); i++) {
        //     std::cout << "v[i] : " << v[i].first << ", " << v[i].second << std::endl;
        // }
        
        ll tmp = 0;
        for (int i = 0; i < v.size() - 1; i++) {
            for (int j = i + 1; j < v.size(); j++) {
                if (v[j].second < (v[i].first * v[i].first))
                    continue;
                else {
                    // std::cout << "i :  "<< i << std::endl;
                    // std::cout << "j :  "<< j << std::endl;
                    ll repeat = v[j].second / (v[i].first * v[i].first);
                    tmp += repeat;
                    for (int k = i + 1; k < j; k++) {
                        if (repeat < (v[k].first * v[k].first)) {
                            break;
                        } else {
                            std::cout << "v[k] : " << v[k].first << ", " << v[k].second << std::endl;
                            std::cout << "repeat : " << repeat << std::endl;  
                            std::cout << "minus!\n";
                            tmp -= repeat / (v[k].first * v[k].first);
                            // repeat %= (v[k].first * v[k].first);
                            // break;
                        }
                    }
                    std::cout << std::endl;
                    // if minus, not ...
                    // v[j].second -= v[j].second / (v[i].first * v[i].first);
                }
            }
        }

        cnt -= tmp;
        // for (int i = 0; i < v.size(); i++) {
        //     std::cout << "v[i] : " << v[i].first << ", " << v[i].second << std::endl;
        // }


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