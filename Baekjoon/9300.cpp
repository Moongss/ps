#include <iostream>
#include <limits>
#include <math.h>
#include <string>
using namespace std;

int main () {
  int t; cin >> t;
  for (int i = 0; i < t; i++) {
    double h, angle; 
    cin >> h >> angle;
    cout << "Case " + to_string(i + 1) + ": ";
    if (angle == 0.0f || angle == 90.0f) cout << "Infinity";
    else  {
      if ((fabs((h / tan(angle*M_PI/180.0f)) - h) > numeric_limits<double>::max())) cout << "Infinity";
      else printf("%.6f", fabs((h / tan(angle*M_PI/180.0f)) - h));
    }
  }
  cout << "\n";
  return 0;
}
