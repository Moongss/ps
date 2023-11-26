#include <iostream>

using namespace std;

int main() {
    int N; cin >> N;
    int a, b, c, d, e, f;
    
    cin >> a >> b >> c >> d >> e >> f;
    int T, P;
    cin >> T >> P;
    
    int tSum = 0;
    tSum += (a + (T - 1)) / T;
    tSum += (b + (T - 1)) / T;
    tSum += (c + (T - 1)) / T;
    tSum += (d + (T - 1)) / T;
    tSum += (e + (T - 1)) / T;
    tSum += (f + (T - 1)) / T;
    
    cout << tSum << endl;
    
    cout << N / P << " " << N % P << endl;
    return 0;
}