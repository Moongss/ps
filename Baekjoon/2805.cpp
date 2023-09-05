#include <iostream>

int N, M;
int treeHeightList[1000000] = {0,};

int main() {
    
    int left = 0, right = 2000000000;
    int mid;
    unsigned long long sum = 0;

    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        std::cin >> treeHeightList[i];
        right = (right < treeHeightList[i]) ? treeHeightList[i] : right;
    }

    while (left + 1 < right) {
        sum = 0;
        mid = (right + left) / 2;
        for (int i = 0; i < N; i++) {
            if (treeHeightList[i] - mid > 0)
                sum += treeHeightList[i] - mid;
        }
        
        if (sum >= M)
            left = mid;
        else
            right = mid;
    }

    std::cout << left << std::endl;
    return 0;
}