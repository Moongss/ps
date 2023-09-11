#include <iostream>

int main() {
    int N, M;
    int arr[100001] = {0, };
    int pre[100001] = {0, };

    std::cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        std::cin >> arr[i];
        pre[i] = pre[i - 1] + arr[i];
    }

    int min = 100000 * 10000;
    int cnt = N - M + 1;
    for (int i = 0; i < N - cnt; i++) {
        int l = i;
        int r = i + cnt;
        int current = pre[r] - pre[l];

        std::cout << "current : " << current << std::endl;
        if (current < min) min = current;
    }
    
    if (min == 100000 * 10000)
        min = 0;

    std::cout << min << std::endl;
    return 0;
}
