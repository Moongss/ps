#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

std::vector<int> v[100001];
int arr[100001] = {0, };

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);

    int N;

    std::cin >> N;
    for (int i = 1; i <= N; i++) {
        int x, y;
        std::cin >> x >> y;

        int tmp = std::max(std::abs(x), std::abs(y));
        v[tmp].push_back(i);
        arr[tmp]++;
    }
    int tmp = 0;
    for (int i = 1; i <= N; i++) {
        tmp += arr[i];
        if (tmp > i || arr[i] > i) {
            std::cout << -1 << std::endl; 
            return 0;
        }
    }

    for (int i = 1; i <= 100000; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            std::cout << v[i][j] << " ";
        }
    }
    std::cout << endl; 
    return 0;
}