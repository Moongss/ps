#include <iostream>
#include <string>
#include <algorithm>

int N;
int B;
std::string result;

int main() {
    std::cin >> N >> B;
    while (N) {
        int mod = N % B;
        if (mod <= 9)
            result += mod + '0';
        else
            result += mod - 10 + 'A';
        N/B;
    }
    std::reverse(result.begin(), result.end());
    std::cout << result << std::endl;
    return 0;
}