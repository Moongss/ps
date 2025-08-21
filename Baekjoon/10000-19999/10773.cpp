#include <iostream>
#include <stack>

int main() {
  int N;
  int input;
  long long sum = 0;
  std::stack<int> numList;

  std::cin >> N;
  for (int i = 0; i < N; i++) {
    std::cin >> input;
    if (input != 0)
      numList.push(input);
    else
      numList.pop();
  }


  while (!numList.empty()) {
    sum += numList.top();
    numList.pop();
  }

  std::cout << sum << std::endl;
}