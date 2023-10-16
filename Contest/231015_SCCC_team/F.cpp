#include <iostream>

using ll = long long;
int N, Q;
bool a[200001];

int main() {
    std::cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        std::cin >> a[i];
    }

    ll result = 0;
    while (Q--) {
        int q, l, r;
        std::cin >> q >> l >> r;
        if (q == 1) {
            for (int i = l; i <= r; i++) {
                a[i] = !a[i]; //segment XOR이 아녔다? 근데 XOR로 할 수 있을거 같은데?
            }
        } else {
            bool flag = a[l];
            ll sum = 1;
            ll tmp = 1;
            for (int i = l + 1; i <= r; i++) {
                sum += 1;
                if (flag == a[i]) {
                    tmp = 1;
                } else {
                    flag = a[i];
                    tmp++;
                    if (tmp >= 2)
                        sum += tmp;
                }
            }
            std::cout << sum << std::endl;
        }
    }
    return 0;
}