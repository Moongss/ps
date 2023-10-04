#include <iostream>
#include <string>

int cnt[26] = {0, };
std::string str;

int main() {
    std::cin >> str;
    for (int i = 0; i < str.length(); i++) {
        cnt[str[i] - 'A']++;
    }

    int oddCnt = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] % 2 == 1)
            oddCnt++;
    }

    if (oddCnt && str.length() % 2 == 0 ||
        oddCnt > 1 && str.length() % 2 == 1) {
        std::cout << "I'm Sorry Hansoo";
        return 0;
    }
    
    if (str.length() % 2 == 0) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < cnt[i] / 2; j++) {
                std::cout << (char)(i + 'A');
            }
        }
        for (int i = 25; i >= 0; i--) {
            for (int j = 0; j < cnt[i] / 2; j++) {
                std::cout << (char)(i + 'A');
            }
        }
    } else {
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 == 0) {
                for (int j = 0; j < cnt[i] / 2; j++) {
                    std::cout << (char)(i + 'A');
                }
            } else {
                for (int j = 0; j < cnt[i] / 2; j++) {
                    std::cout << (char)(i + 'A');
                }
            }
        }
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 == 1)
                std::cout << (char)(i + 'A');
        }
        for (int i = 25; i >= 0; i--) {
            if (cnt[i] % 2 == 0) {
                for (int j = 0; j < cnt[i] / 2; j++) {
                    std::cout << (char)(i + 'A');
                }
            } else {
                for (int j = 0; j < cnt[i] / 2; j++) {
                    std::cout << (char)(i + 'A');
                }
            }
        }
    }
    return 0;
}