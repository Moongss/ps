#include <iostream>

int main() {
    int N;
    int zero_cnt[2] = {0,};

    std::cin >> N;
    for (int i = 1; i <= N; i++) {
        int tmp = i;
        while (tmp % 2 == 0 || tmp % 5 == 0) {
            if (tmp % 2 == 0) {zero_cnt[0]++; tmp /= 2;}
            if (tmp % 5 == 0) {zero_cnt[1]++; tmp /= 5;}
        }
    }

    if (zero_cnt[0] > zero_cnt[1])
        std::cout << zero_cnt[1] << std::endl;
    else
        std::cout << zero_cnt[0] << std::endl;
    
    return 0;
}