#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;

        std::string x;
        std::string s;
        std::cin >> x >> s;

        bool flag = false;
        int cnt = 0;
        for (int i = 0; ; i++) {

            if (x.find(s) != std::string::npos) {
                std::cout << cnt << std::endl;
                flag = true;
                break;
            }
            x += x;
            cnt++;
            if (i == 10)
                break;
        }
        if (!flag)
            std::cout << -1 << std::endl;
    }
    return 0;
}