#include <iostream>
#include <algorithm>

using ll = long long;
int N;
ll A[50001] = {0, };

int main() {
    std::cin >> N;

    for (int i = 1; i <= N; i++) {
        std::cin >> A[i];
    }

    std::sort(A, A + N + 1);
    ll min = 1000000001;
    for (int i = 1; i <= N; i++) {
        if (A[i] / i != 0)
            min = std::min(min, A[i] / i);
    }
    std::cout << min << std::endl;
    return 0;
}  