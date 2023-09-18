#include <iostream>
#include <vector>
#include <algorithm>

int N;
int p[6] = {0, };
std::vector<int> problem[6];

int main() {
    std::cin >> N;
    for (int i = 1; i <= 5; i++) {
        std::cin >> p[i];
    }

    for (int i = 0; i < N; i++) {
        int difficulty, time;
        std::cin >> difficulty >> time;
        problem[difficulty].push_back(time);
    }

    for (int i = 1; i <= 5; i++) {
        std::sort(problem[i].begin(), problem[i].end());
    }

    // std::cout << "test" << std::endl;
    int result = 0;
    bool isLevelUp = false;
    for (int i = 1; i <= 5; i++) {
        int tmp = p[i];

        int cur = 0;
        int prev = 0;
        int idx = 0;
        if (tmp == 0)
            continue;

        while(tmp--) {
            cur = problem[i][idx];

            // std::cout << "cur : " << cur << std::endl;
            // std::cout << "cur - prev : " << cur - prev << std::endl;
            result += cur;
            if (prev)
                result += cur - prev; // 휴식
            prev = cur;
            idx++;
        }

        if (isLevelUp) {
            result += 60;
            // std::cout << "levelup : " << 60 << std::endl;
        }

        isLevelUp = true;
    }
    std::cout << result << std::endl;
    return 0;
}