#include <iostream>
#include <climits>

int main() {
    int N, K;
    int arr[10000] = {0, };

    std::cin >> N >> K;
    for (int i = 0; i < N; i++){
        std::cin >> arr[i];
    }

    long lo = 0;
    int hi = INT_MAX;
    
    //1 2 3 4 5 6 
    // 
    while (lo + 1 < hi) {
        int cnt = 0;
        long mid = (lo + hi) / 2; // lo += hi
        for (auto i : arr) {
            cnt += i / mid;
        }

        if (cnt >= K) lo = mid;
        else hi = mid;
    }
    std::cout << lo << std::endl;
    return 0;
}