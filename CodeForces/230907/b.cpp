#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    int N;
    std::cin >> T;

    for (int i = 0; i < T; i++) {
        std::cin >> N;
        int result = 1000000;
        for (int j = 0; j < N; j++) {
            int d, s;
            std::cin >> d >> s;
            int tmp = d + (s-1)/2;
            if (tmp < result)
                result = tmp;
        }
        std::cout << result << std::endl;
    }

    return 0;
}