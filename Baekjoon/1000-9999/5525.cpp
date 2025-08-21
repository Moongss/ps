#include <iostream>
#include <string>
#include <cstring>

int main() {
    int N, M, sum = 0;
    std::string target;
    std::string source;

    std::cin >> N >> M;
    std::cin >> source;

    int idx = 0;
    int tmp = 0;
    while (idx < M) {
        if (source[idx] == 'I') {
            while (source[idx + 1] == 'O' && source[idx + 2] == 'I') {
                tmp++;
                idx += 2;
                if (tmp == N) {
                    tmp--;
                    sum++;
                }
            }
        }
        tmp = 0;
        idx++;
    }
    std::cout << sum << std::endl;
    return 0;
}