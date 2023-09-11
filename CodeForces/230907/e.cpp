#include <iostream>
#include <string>
using namespace std;

int n;
int arr[100001] = {0, };
int sum[100001] = {0, };
std::string s;
int q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    std::cin >> t;

    while (t--) {
        sum[0] = 0;
        int xor_0 = 0;
        int xor_1 = 0;

        std::cin >> n;
        for (int i = 1; i <= n; i++) {
            std::cin >> arr[i];
            sum[i] = sum[i - 1] ^ arr[i];
        }

        std::cin >> s;
        for (size_t i = 0; i < s.length(); i++) {
            if (s[i] == '0')
                xor_0 ^= arr[i + 1];
            if (s[i] == '1')
                xor_1 ^= arr[i + 1];
        }

        std::cin >> q;
        while (q--) {
            int tp;
            int l, r, g;

            std::cin >> tp;
            if (tp == 1) {
                std::cin >> l >> r;
                xor_0 ^= sum[r] ^ sum[l - 1];
                xor_1 ^= sum[r] ^ sum[l - 1];
            } else if (tp == 2) {
                std::cin >> g;
                std::cout << (g ? xor_1 : xor_0) << " ";
            }
        }
        std::cout << std::endl;
    }
    return 0;
}