#include <iostream>
#include <vector>

int N;
std::vector<int> triVector;
bool isEurekaNum[1001] = {
    false,
};

int main() {

  int current = 0;
  for (int i = 1; i <= 45; i++) { // Sum 1~45 is 1035.
    current += i;
    triVector.push_back(current);
  }

  for (int i = 0; i < triVector.size(); i++) {
    for (int j = 0; j < triVector.size(); j++) {
      for (int k = 0; k < triVector.size(); k++) {
        if (triVector[i] + triVector[j] + triVector[k] <= 1000)
          isEurekaNum[triVector[i] + triVector[j] + triVector[k]] = true;
      }
    }
  }

  // for (int i = 3; i <= 1000; i++) {
  //   if (!isEurekaNum[i]) std::cout << i << " ";
  // }
  
  std::cin >> N;
  for (int i = 0; i < N; i++) {
    int tmp;
    std::cin >> tmp;
    std::cout << (isEurekaNum[tmp] ? 1 : 0) << std::endl;
  }
  return 0;
}