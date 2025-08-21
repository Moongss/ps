#include <iostream>

int N;
int arr[100000];
int tmp[100000];
int result = 424242;

void solve(int color) {
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        tmp[i] = arr[i];
    }

    for (int i = 0; i < N - 2; i++) {
        while (tmp[i] != color) {
            tmp[i]++;
            tmp[i + 1]++;
            tmp[i + 2]++;

            tmp[i] %= 3;
            tmp[i + 1] %= 3;
            tmp[i + 2] %= 3;
            cnt++;
        }
    }

    if (tmp[N - 3] == tmp[N - 2] && tmp[N - 2] == tmp[N - 1])
        result = std::min(result, cnt);
}

int main() {
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        char ch;
        std::cin >> ch;
        if (ch == 'R') arr[i] = 0;
        if (ch == 'G') arr[i] = 1;
        if (ch == 'B') arr[i] = 2;
    }

    for (int i = 0; i < 3; i++) {
        solve(i);
    }

    if (result == 424242)
        std::cout << -1 << std::endl;
    else
        std::cout << result << std::endl;
    return 0;
}