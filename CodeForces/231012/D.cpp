
#include <bits/stdc++.h>
using namespace std;

int cnt[100000] = {0, };

int prime[1000000] = {0, };
std::vector<int> v;

void primeSet() {
    for (int i = 2; i <= 1000000; i++) {
        prime[i] = i;
    }
    
    for (int i = 2; i <= 1000000; i++) {
        if (prime[i] == 0) continue;
        for (int j = i + i; j <= 1000000; j += i) {
            prime[j] = 0;
        }
    }

    for (int i = 2; i <= 1000000; i++) {
        if (prime[i])
            v.push_back(i);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    primeSet();
    int t;
    cin >> t;
    while (t--) {
        int n;
        std::cin >> n;


        for (int i = 0; i < 100000; i++) {
            cnt[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            

            int k = 0;            
            while (x != 1) {
                if (x % v[k] == 0) {
                    cnt[k]++;
                    x /= v[k];
                } else {
                    k++;
                }
            }
        }

        bool flag = true;
        for (int i = 0; i < 100000; i++) {
            if (cnt[i] > 0 && cnt[i] % n != 0) {
                flag = false;
                break;
            }
        }

        if (flag)
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;
    }
    return 0;
}