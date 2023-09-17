#include <iostream>
#include <string>
#include <set>

bool isSplitChar[1000] = {false, };

int main() {
    int N, M, K, S;
    std::string str;
    char ch;

    std::cin >> N;
    isSplitChar[' '] = true;
    for (int i = 0; i < N; i++) {
        std::cin >> ch;
        if (!isSplitChar[ch])
            isSplitChar[ch] = true;
    }

    std::cin >> M;
    for (int i = 0; i < M; i++) {
        std::cin >> ch;
        if (!isSplitChar[ch])
            isSplitChar[ch] = true;
    }
    
    std::cin >> K;
    for (int i = 0; i < K; i++) {
        std::cin >> ch;
        if (isSplitChar[ch])
            isSplitChar[ch] = false;
    }
    std::cin >> S;
    ch = getchar();
    std::string tmp = "";
    for (int i = 0; i < S; i++) {
        ch = getchar();
        if (!isSplitChar[ch])
            tmp += ch;
        else {
            if (tmp.length() > 0)
                std::cout << tmp << std::endl;
            tmp = "";
        }
    }
    if (tmp.length() > 0)
        std::cout << tmp << std::endl;
    return 0;
}