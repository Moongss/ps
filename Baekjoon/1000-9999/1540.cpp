#include <iostream>

using ll = long long;

int N;
int i = 1;
ll sum = 0;

int main() {
    std::cin >> N;
    if (N < 4) {    
        std::cout << 0 << std::endl;
        return 0;
    }

    for (;i * i <= N; i++) {
        if (i * i == N) {
            std::cout << sum << std::endl;
            return 0;
        }
        sum += i * i;
    }
    i--;
    sum -= (i * i);

    int mid = (i * i) + (i + 1);
    if (N < mid) {
        for (int j = (i * i); j < N; j++) {
            sum += j - (i * i);
        }
    }
    if (N >= mid) {
        for (int j = (i * i); j < mid - 1; j++) {
            sum += j - (i * i);
        }
        for (int j = mid; j <= N; j++) {
            sum += (j - mid);
        }
    }
    std::cout << sum << std::endl;
    return 0;
}