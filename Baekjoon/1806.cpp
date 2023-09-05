#include <iostream>

#define IMPOSSIBLE 100000
short arr[100001] = {0, };

int main() {
    int N, S;
    int result = IMPOSSIBLE;

    std::cin >> N >> S;
    for (int i = 1; i <= N; i++) {
        std::cin >> arr[i];
    }

    int start = 0;
    int end = start + 1;

    int cnt = 2;
    int sum = arr[start] + arr[end];

    while (start <= end && end <= N) {
        if (sum < S) {
            end++;
            sum += arr[end];
            cnt++;
        }
        else {
            if (result > cnt)
                result = cnt;
            sum -= arr[start];
            start++;
            cnt--;
        }
    }
    
    if (result == IMPOSSIBLE)
        std::cout << 0 << std::endl;
    else
        std::cout << result << std::endl;
    return 0;
}