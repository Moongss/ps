#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int main() {
    fastio;
    
    double x1, y1, x2, y2, x3, y3;
    while (true) {
        string str; getline(cin, str);
        
        if (str.length() < 4) break;
        stringstream ss(str);
        ss >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        double edge1 = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
        double edge2 = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
        double edge3 = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));

        if (edge1 + edge2 <= edge3 || edge2 + edge3 <= edge1 || edge3 + edge1 <= edge2) {
            cout << "Not a Triangle" << endl;
            continue;
        }

        if (abs(edge1 - edge2) < 1e-2 && abs(edge2 - edge3) < 1e-2 && abs(edge3 - edge1) < 1e-2)
            cout << "Equilateral ";
        else if (abs(edge1 - edge2) < 1e-2 || abs(edge2 - edge3) < 1e-2 || abs(edge3 - edge1) < 1e-2)
            cout << "Isosceles ";
        else
            cout << "Scalene ";

        double innerProduct1 = (x2 - x1) * (x3 - x1) + (y2 - y1) * (y3 - y1);
        double innerProduct2 = (x1 - x2) * (x3 - x2) + (y1 - y2) * (y3 - y2);
        double innerProduct3 = (x2 - x3) * (x1 - x3) + (y2 - y3) * (y1 - y3);
        
        if (abs(innerProduct1) < 1e-2 || abs(innerProduct2) < 1e-2 || abs(innerProduct3) < 1e-2)
            cout << "Right" << endl;
        else if (innerProduct1 < 0 || innerProduct2 < 0 || innerProduct3 < 0)
            cout << "Obtuse" << endl;
        else 
            cout << "Acute" << endl;
    }
    return 0;
}
