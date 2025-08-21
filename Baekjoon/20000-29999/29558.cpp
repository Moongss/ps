#include <iostream>

using namespace std;
int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);

    int N, D;
    std::cin >> N >> D;
    
    if (N % 2 == 1)
        cout << D << " ";
    
    for (int i = 1; i <= N / 2; i++) {
        cout << D + i << " ";
        cout << D - i << " ";
    }
    cout << endl;
    return 0;
}