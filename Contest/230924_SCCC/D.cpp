#include <iostream>
#include <cmath>

using namespace std;
int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);

    long long N;
    std::cin >> N;

    if (N == 0)
        std::cout << 0 << "\n";
    else {
        for (long long i = sqrt(N); i >= 1; i++) {
            if (N % i == 0) {
        		std::cout << i + N / i << "\n";
        		break;
            }
        }
    }

    return 0;
}