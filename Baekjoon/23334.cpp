#include <iostream>
#include <string>
#include <vector>

int N;
int g[301], s[301], b[301];
std::string str[301];
std::vector<int> res;
std::vector<int> res2;
std::vector<int> res3;

int main() {
    std::cin.tie(0)->sync_with_stdio(false);

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> g[i] >> s[i] >> b[i];
        std::getline(std::cin, str[i]);
    }

    int max = -1;
    for (int i = 0; i < N; i++) {
        if (g[i] > max) {
            max = g[i];
            res.clear();
            res.push_back(i);
        } else if (g[i] == max) {
            res.push_back(i);
        }
    }

    max = -1;
    for (auto i : res) {
        if (s[i] > max) {
            max = s[i];
            res2.clear();
            res2.push_back(i);
        } else if (s[i] == max) {
            res2.push_back(i);
        }
    }

    max = -1;
    for (auto i : res2) {
        if (b[i] > max) {
            max = b[i];
            res3.clear();
            res3.push_back(i);
        } else if (b[i] == max) {
            res3.push_back(i);
        }
    }

    int tmp = 0;
    std::string result = str[res3.front()];
    for (int i = 0; i < result.length(); i++) {
        if (result[i] == ' ') {
            tmp++;
            continue;
        } else {
            break;
        }
    }

    int tmp2 = 0;
    for (int i = result.length() - 1; i >= 0; i--) {
        if (result[i] == ' ') {
            continue;
        } else {
            tmp2 = i;
            break;
        }
    }

    std::cout << result.substr(tmp, tmp2 - tmp + 1) << std::endl;
    return 0;
}