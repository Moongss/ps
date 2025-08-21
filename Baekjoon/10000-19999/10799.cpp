#include <iostream>
#include <stack>
#include <string>

int main() {
  int result = 0;
  std::string str;
  std::stack<char> save;

  std::cin >> str;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == '(')
      save.push(str[i]);
    if (str[i] == ')') {
      save.pop();
      if (str[i - 1] == '(') { // not index err
        result += save.size();
      } else {
        result += 1;
      }
    }
  }

  std::cout << result << std::endl;
  return 0;
}