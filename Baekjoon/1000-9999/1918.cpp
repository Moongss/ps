#include <iostream>
#include <stack>
#include <string>


int main() {
  int level = 0;
  int idx = 0;
  std::string notation;
  std::stack<std::pair<int, char> > operatorStack;
  
  std::cin >> notation;
  while (notation[idx]) {
    if (notation[idx] == '*' || notation[idx] == '/') {
        while (!operatorStack.empty() 
              && operatorStack.top().first == level
              && (operatorStack.top().second == '*' || operatorStack.top().second == '/')) {
        std::cout << operatorStack.top().second;
        operatorStack.pop();      
      }
      operatorStack.push({level, notation[idx]});
    }
    else if (notation[idx] == '+' || notation[idx] == '-') {
      while (!operatorStack.empty() 
        && operatorStack.top().first == level) {
        std::cout << operatorStack.top().second;
        operatorStack.pop();      
      }
      operatorStack.push({level, notation[idx]});
    }
    else if (notation[idx] == '(')
      level++;
    else if (notation[idx] == ')') {
      while (!operatorStack.empty() 
        && operatorStack.top().first == level) {
        std::cout << operatorStack.top().second;
        operatorStack.pop();      
      }
      level--;
    }
    else //alpha
      std::cout << notation[idx];
    idx++;
  }

  while (!operatorStack.empty()) {
    std::cout << operatorStack.top().second;
    operatorStack.pop();
  }

  return 0;
}