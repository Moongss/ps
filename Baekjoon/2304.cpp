#include <iostream>
#include <map>

std::map<int, int> line;

int N;
int L, H;

int main() {
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> L >> H;
        line.insert({L, H});
    }

    int before = 0;
    int beforeHeight = 0;
    int result = 0;
    for (std::map<int, int>::iterator iter = line.begin(); iter != line.end(); iter++) {
        int cur = iter->first;
        int curHeight = iter->second;
        if (beforeHeight <= curHeight) {
            // std::cout << "L : " << iter->first << ", R : " << iter->second << std::endl;
            result += abs(cur - before) * beforeHeight;
            // std::cout << "result : " << abs(cur - before) * beforeHeight << std::endl;
            beforeHeight = curHeight;
            before = cur;
        }
    }
    result += beforeHeight;

    //리버스로 진행.
    before = line.size() - 1;
    beforeHeight = 0;
    for (std::map<int, int>::reverse_iterator iter = line.rbegin(); iter != line.rend(); iter++) {
        int cur = iter->first;
        int curHeight = iter->second;
        if (beforeHeight < curHeight) {
            // std::cout << "L : " << iter->first << ", R : " << iter->second << std::endl;
            result += abs(cur - before) * beforeHeight;
            // std::cout << "result : " << abs(cur - before) * beforeHeight << std::endl;
            beforeHeight = curHeight;
            before = cur;
        }
    }

    std::cout << result << std::endl;
    return 0;
}