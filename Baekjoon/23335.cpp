#include <iostream>

using ll = long long;
int T;

ll solve(ll num) {
    ll sum = 0;
    ll tmp = 1;
    while (tmp * tmp <= num) { //sqrt(N)
        if (num % tmp == 0) {
            sum += (tmp + num / tmp);
        }
        if (num % tmp == 0 && num / tmp == tmp)
            sum -= tmp;
        tmp++;
    }
    return sum;
}

int main() {
    std::cin.tie(0)->sync_with_stdio(false);
    std::cin >> T;
    while (T--) {
        ll num;
        std::cin >> num;

        ll sum = solve(num) - num;
        if (sum > num) {
            std::cout << "abundant\n";
        } else if (sum == num) {
            std::cout << "perfect\n";
        } else {
            std::cout << "deficient\n";
        }
    }
    return 0;
}

