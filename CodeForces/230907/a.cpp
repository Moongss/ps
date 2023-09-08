#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        
        double mid = (a + b) / 2;

        int max = a;
        if (a < b)
            max = b;

        double result = (max - mid) / c;
        std::cout << ceil(result) << std::endl;
    }
    return 0;
}