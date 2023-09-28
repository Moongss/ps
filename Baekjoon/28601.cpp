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
        long long i = sqrt(N);

        if (i * i == N)
            std::cout << i + i << "\n";
        else if (i * i < N && N <= i * (i + 1)) 
            std::cout << i + i + 1 << "\n";
        else 
            std::cout << i + i + 2 << "\n";
    }
    return 0;
}