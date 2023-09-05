#include <iostream>
#include <stack>

int N;
std::stack<int> input;
std::stack<int> tmp;
std::stack<int> result;

int main() {
  std::cin >> N;
  for (int i = 0; i < N; i++) {
    int val;
    std::cin >> val;
    input.push(val);
  }

  while (!input.empty()) {
    int current = input.top();
    input.pop();

    if (tmp.empty()) {
      result.push(-1);
    } else {
      while (!tmp.empty()) {
        if (current < tmp.top())
          break;
        tmp.pop();
      }
      if (tmp.empty())
        result.push(-1);
      else
        result.push(tmp.top());
    }
    tmp.push(current);
  }

  while (!result.empty()) {
    std::cout << result.top() << " ";
    result.pop();
  }
  return 0;
}