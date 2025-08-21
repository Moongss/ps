#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int N;
  int input;
  std::vector<int> coordinates;
  std::vector<int> uniqueCoords;

  std::cin >> N;
  for (int i = 0; i < N; i++) {
    std::cin >> input;
    coordinates.push_back(input);
    uniqueCoords.push_back(input);
  }

  std::sort(uniqueCoords.begin(), uniqueCoords.end());
  uniqueCoords.erase(std::unique(uniqueCoords.begin(), uniqueCoords.end()), uniqueCoords.end());

  for (int i = 0; i < coordinates.size(); i++) {
    std::cout << std::lower_bound(uniqueCoords.begin(), uniqueCoords.end(), coordinates[i]) - uniqueCoords.begin() << " ";
  }

  return 0;
}