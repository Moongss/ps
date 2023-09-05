#include <iostream>
#include <string>

int N;
std::string A, B;

int main() {
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> A >> B;

        bool test = false;
        if (A == B) {
            std::cout << "YES\n";
            continue;
        }
        for (int i = 0; i < A.length() - 1; i++) {
            if (A[i] == B[i] && A[i] == '0' && A[i + 1] == B[i + 1] && A[i + 1] == '1') {
                test = true;
                break;
            }
        }

        if (test)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
    return 0;
}