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
        int tmp = 0;
        int zeroIdx = 0;

        std::cin >> n;
        for (int i = 0; i < n; i++) {
            std::cin >> tmp;
        }

        if (n % 2 != 0) {
            std::cout << "4" << std::endl;
            std::cout << "1 " << n - 1 << std::endl;
            std::cout << "1 " << n - 1 << std::endl;
            std::cout << n - 1 << " " << n << std::endl;
            std::cout << n - 1 << " " << n << std::endl;
        } else {
            std::cout << 2 << std::endl;
            std::cout << "1 " << n << std::endl;
            std::cout << "1 " << n << std::endl;
        }
    }
    
    return 0;
}