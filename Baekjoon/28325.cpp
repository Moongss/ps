#include <iostream>

int N;
long long cnt[250000] = {0, };

int main() {
    long long result = 0;
    int maxIdx = 0;
    long long max = -1;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> cnt[i];
        result += cnt[i];
        if (cnt[i] > max) {
            max = cnt[i];
            maxIdx = i;
        }
    }

    if (result == 0) {
        std::cout << N / 2 << std::endl;
        return 0;
    } else {
        for (int i = maxIdx; i < N + maxIdx; i++) {
            if (cnt[i % N]) {
                continue;
            }
            else {
                int tmp = 0;
                while (!cnt[i % N]) {
                    tmp++;
                    i++;
                }
                result += (tmp + 1) / 2;
                i--;
            }
        }
    }

    std::cout << result << std::endl;
    return 0;
}
