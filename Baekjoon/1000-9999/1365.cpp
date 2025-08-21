#include <iostream>

int N;
int arr[100000];
int dp[100000] = {0, };

int main() {
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    int current = 0;
    for (int i = 0; i < N; i++) {
        if (dp[current] < arr[i]) {
            dp[++current] = arr[i];
        } else {
            int lo = 0;
            int hi = current;
            while (lo + 1 < hi) {
                int mid = (lo + hi) / 2;
                if (dp[mid] < arr[i]) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }
            dp[hi] = arr[i];
        }
    }

    std::cout << N - current << std::endl;
    return 0;
}