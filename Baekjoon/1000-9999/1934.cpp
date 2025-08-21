#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    int N;
    int a, b;
    cin >> N;
    while (N--) {
        cin >> a >> b;
        cout << a * b / gcd(a, b) << endl;
    }
    return 0;
}