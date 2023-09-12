#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    std::cin >> t;
    while (t--) {
        int arr[400000] = {0, };
        priority_queue<std::pair<int, int> >pq;
        int n;
        int a;
        std::cin >> n;
        for (int i = 0; i < n; i++) {
            std::cin >> a;
            pq.push({a, i});
        }    

        for (int i = 0; i < n; i++) {
            std::pair<int, int> elem = pq.top();
            pq.pop();
            arr[elem.second] = i + 1;
        }

        for (int i = 0; i < n; i++) {
            if (arr[i] != 0) {
                std::cout << arr[i] << " ";
            }
        }
        std::cout << std::endl;
    }
    return 0;
}