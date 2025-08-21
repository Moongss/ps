#include <iostream>

int N, M;
int arr[200002];
int maxArr[200002];
int minArr[200002];

int main() {
    std::cin >> N >> M;

    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    int minValue = arr[0];
    int maxValue = arr[N - 1];
    for (int i = 0; i < N; i++) {
        minArr[i] = minValue;
        if (arr[i] < minValue) {
            minValue = arr[i];
            minArr[i] = minValue;
        }

        maxArr[N - i - 1] = maxValue;
        if (arr[N - i - 1] > maxValue) {
            maxValue = arr[N - i - 1];
            maxArr[N - i - 1] = maxValue;
        }
    }


    int result = arr[N-1] - arr[0];
    int cur = arr[0];
    for (int i = 0; i <= M; i++) {
        if (result < maxArr[N - 1 - (M - i)] - minArr[i])
            result = maxArr[N - 1 - (M - i)] - minArr[i];
    }

    std::cout << result << std::endl;
    return 0;
}