#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, time;
    std::vector<int> usingTimeList;

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> time;
        usingTimeList.push_back(time);
    }
    std::sort(usingTimeList.begin(), usingTimeList.end());

    int tmp = 0;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        tmp += usingTimeList[i];
        sum += tmp;
    }
    std::cout << sum << std::endl;
}