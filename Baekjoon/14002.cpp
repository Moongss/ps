#include <iostream>
#include <vector>
#include <stack>

int N;
int arr[1000000];
int dp[1000000] = {0, };
std::vector<int> save;
int main() {
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
        dp[i] = 0;
    }

    int current = 0;
    for (int i = 0; i < N; i++) {
        if (dp[current] < arr[i]) {
            dp[++current] = arr[i];
            save.push_back(current);
        } else {
            int lo = 0;
            int hi = current;
            while (lo + 1 < hi) {
                int mid = (lo + hi) / 2;
                if (dp[mid] < arr[i]) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }

            dp[hi] = arr[i];
            save.push_back(hi);
        }
    }

    std::cout << current << std::endl;
    int target = current;

    std::stack<int> s;
    for (int i = save.size() - 1; i >= 0 && current > 0; i--) {
        if (save[i] == current) {
            s.push(arr[i]);
            current--;
        }
    }

    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
    return 0;
}