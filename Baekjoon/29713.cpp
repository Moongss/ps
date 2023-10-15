#include <iostream>
#include <string>
#include <algorithm>

int N;
int ch[26];
std::string str;

int main() {
    std::cin >> N;
    std::cin >> str;
    for (auto i : str) {
        ch[i - 'A']++;
    }

    int min = 4242;
    min = std::min(min, ch['R' - 'A'] / 2);
    min = std::min(min, ch['E' - 'A'] / 2);
    min = std::min(min, ch['B' - 'A']);
    min = std::min(min, ch['O' - 'A']);
    min = std::min(min, ch['N' - 'A']);
    min = std::min(min, ch['Z' - 'A']);
    min = std::min(min, ch['S' - 'A']);
    min = std::min(min, ch['I' - 'A']);
    min = std::min(min, ch['L' - 'A']);
    min = std::min(min, ch['V' - 'A']);
    std::cout << min << std::endl;
    return 0;
}