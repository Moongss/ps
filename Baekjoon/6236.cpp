#include <iostream>

int main() {
    int N, M;
    int arr[100001] = {0, };

    int min = 1000000;
    int max = -1;
    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];

        max = (max < arr[i]) ? arr[i] : max;
        min = (min > arr[i]) ? arr[i] : min;
    }

    long lo = 1;
    long hi = 10000 * 100000;
    while (lo + 1 < hi) {

        long mid = (lo + hi) / 2;
        int cnt = 0;
        int money = 0;
        for (int i = 0; i < N; i++) {
            if (mid < arr[i]) {
                cnt = M + 1;
                break;
            }
            while (money < arr[i]) {
                money = mid;
                cnt++;
            }
            money -= arr[i];
        }
        
        // std::cout << "mid : " << mid << std::endl;
        // std::cout << "cnt : " << cnt << std::endl;
        //M = 1 2 3 4 5 6 7 8 9
        //M = f f f f t t t t t
        if (cnt <= M) hi = mid;
        else lo = mid;
    }
    std::cout << hi << std::endl;
    return 0;
}
