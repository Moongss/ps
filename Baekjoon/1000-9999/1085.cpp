#include <iostream>
#include <string>

int main() {
  
  int x, y, w, h;
  int minDistance;
  int rowDistance;
  int colDistance;

  std::cin >> x >> y >> w >> h;
  rowDistance = w - x;
  colDistance = h - y;

  minDistance = (x > y) ? y : x;
  minDistance = (minDistance > rowDistance) ? rowDistance : minDistance;
  minDistance = (minDistance > colDistance) ? colDistance : minDistance;

  std::cout << minDistance << std::endl;
  return 0;
}