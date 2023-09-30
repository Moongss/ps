#include <iostream>
#include <algorithm>

int N;
int arr[100000];

int main() {
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    std::sort(arr, arr + N);
    
    int lo = 0;
    int hi = N - 1;
    int min = INT32_MAX;
    std::pair<int, int> result;

    while (lo < hi) {
        int tmp = (arr[lo] + arr[hi]);

        if (min > std::abs(tmp)) {
            min = std::abs(tmp);
            result = {arr[lo], arr[hi]};
        }
    
        if (tmp > 0) {
            hi--;
        } else if (tmp < 0) {
            lo++;
        } else {
            break;
        }
    }
    std::cout << result.first << " " << result.second << std::endl;
    return 0;
}