#include <iostream>

int prime[10001];

void setSieve() {
    for (int i = 2; i <= 10000; i++) {
        prime[i] = i;
    }
    
    for (int i = 2; i <= 10000; i++) {
        if (prime[i] == 0) continue;
        for (int j = i + i; j <= 10000; j += i) {
            prime[j] = 0;
        }
    }
}

int main() {
    int M, N;
    int sum = 0;
    int firstPrime;
    std::cin >> M >> N;

    setSieve();
    for (int i = M; i <= N; i++) {
        if (prime[i]) sum += i;
        if (sum == i) firstPrime = i;
    }
    if (sum == 0)
        std::cout << -1 << "\n";
    else
        std::cout << sum << "\n" << firstPrime << "\n";
    return 0;
}