#include <iostream>
#include <vector>
#include <string>
#include <cstring>

unsigned int bitset = 0b000000000000000000000;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string command;
    int targetNum;
    int M;
    int tmp;
    std::cin >> M;
    for (int i = 0; i < M; i++) {
        std::cin >> command;
        if (command == "add") {
            std::cin >> targetNum;
            bitset |= (1 << (targetNum - 1));
        }
        if (command == "remove") {
            std::cin >> targetNum;
            bitset &= ~(1 << (targetNum - 1));
        }
        if (command == "check") {
            std::cin >> targetNum;
            tmp = (bitset & (1 << (targetNum - 1))) ? 1 : 0;
            std::cout <<  tmp << "\n";
        }
        if (command == "toggle") {
            std::cin >> targetNum;
            bitset ^= (1 << (targetNum - 1));
        }
        if (command == "all")
            bitset = 0b11111111111111111111;
        if (command == "empty")
            bitset = 0;
    }
    return 0;
}