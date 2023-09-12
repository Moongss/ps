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
        std::set<int> s;
        std::cin >> n;
        for (int i = 0; i < n; i++) {
            int a;
            std::cin >> a;
            s.insert(a);
        }

        int bobResult;


        //output
        int tmp;
        for (int i = 0; i <= 100000; i++) {
            if (s.find(i) == s.end()) {
                std::cout << i << std::endl;
                std::cout.flush();
                s.insert(i);
                break;
            }
        }

        while (true) {
            //read
            std::cin >> bobResult;
            if (bobResult >= 0)
                tmp = bobResult;
            else if (bobResult == -1)
                break;
            else
                return -1;

            std::cout << tmp << std::endl;
            std::cout.flush();
        }
    }
    return 0;
}