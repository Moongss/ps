#include <iostream>

using namespace std;
int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);

    int N;
    int pos = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int move;
        cin >> move;

        pos += move;
    }

    if (pos > 0) cout << "Right\n";
    else if (pos < 0) cout << "Left\n";
    else cout << "Stay\n";

    return 0;
}