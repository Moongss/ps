#include <iostream>
#include <vector>

int main() {
    int N;
    std::vector<int> v;

    while (true) {
        std::cin >> N;
        if (N == -1)
            break;

        v.clear();
        int sum = 0;
        for (int i = 1; i < N; i++) {
            if (N % i == 0) {
                sum += i;
                v.push_back(i);
            }
        }

        if (sum != N)
            std::cout << N << " is NOT perfect.\n";
        else {
            std::cout << N << " = ";
            for (int i = 0; i < v.size() - 1; i++) {
                std::cout << v[i] << " + ";
            }
            std::cout << v.back() << "\n";
        }
    }

    return 0;
}