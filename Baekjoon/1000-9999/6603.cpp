#include <iostream>
#include <vector>
#include <queue>

int N;
int num;
std::vector<int> arr;
std::vector<int> save;

void print() {
    for (int i = 0; i < 6; i++) {
        std::cout << save[i] << " ";
    }
    std::cout << std::endl;
}

void solve(int idx) {
    if (save.size() == 6) {
        print();
        return;
    }

    for (int i = idx; i < arr.size(); i++) {
        save.push_back(arr[i]);
        solve(i + 1);
        save.pop_back();
    }
}

int main() {
    while (true) {
        std::cin >> N;
        if (N == 0)
            break;

        arr.clear();
        save.clear();
        for (int i = 0; i < N; i++) {
            std::cin >> num;
            arr.push_back(num);
        }

        solve(0);
        std::cout << std::endl;
    }
    return 0;
}