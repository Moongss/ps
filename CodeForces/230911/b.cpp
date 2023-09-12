#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::string str;

        std::cin >> n;
        std::cin >> str;

        int diff = 0;
        for (int i = 0; i < str.length() / 2; i++) {
            if (str[i] != str[str.length() - i - 1])
                diff++;
        }

        for (int i = 0; i < diff; i++) {
            std::cout << "0";
        }
        if (str.length() % 2 != 0) {
            for (int i = diff; i <= str.length() / 2; i++) {
                std::cout << "1";
            }
            for (int i = diff; i <= str.length() / 2; i++) {
                std::cout << "1";
            }

        } else {
            std::cout << "1";
            for (int i = diff; i < str.length() / 2; i++) {
                std::cout << "01";
            }
        }
        for (int i = 0; i < diff; i++) {
            std::cout << "0";
        }
        std::cout << std::endl;
    }
    return 0;
}