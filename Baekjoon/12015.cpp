#include <iostream>
#include <vector>

#define MIN 0

int main() {
    int N;
    int input;
    std::vector<int> save;

    std::cin >> N;
    save.push_back(MIN);
    for (int i = 0; i < N; i++) {
        std::cin >> input;
        if (save.back() < input) {
            save.push_back(input);
        }
        else {
            std::vector<int>::iterator target = std::lower_bound(save.begin(), save.end(), input);
            *target = input;
        }
    }

    std::cout << save.size() - 1 << std::endl;
    return 0;
}