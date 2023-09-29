#include <iostream>

using ll = long long;

ll N, L, W, H;

int main() {
    std::cin >> N >> L >> W >> H;
    
    long double lo = 0; 
    long double hi = 1000000000;
    while (lo + 1e-9 < hi) {
        long double mid = (lo + hi) / 2;
        
        ll tmp = (ll)(L / mid) * (ll)(W / mid) * (ll)(H / mid);
        if (tmp < N) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    
    printf("%.10Lf\n", lo); // WA: print err
    return 0;
}